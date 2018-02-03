//Antoine Innocent BA2 Informatique
//Matricule: 000394700



package packaging;


import java.util.Arrays;

public class Sort extends Thread
{
	
	////////////// Variables ////////////////////////
	
	 private static int[] resArray={};
	 private int[] myArray={};
	 private int currProcess=0;
	 private int nextBegin=0;
	 private int nextEnd=0;
	 private int currBegin=0;
	 private int currEnd=0;
	 private int prevBegin=0;
	 private int prevEnd=0;
	 private int numberOfSteps=0;
	 ThreadControl tControle;


	 
	
	 /////////////////// Constructor ////////////////////////////
	 public Sort(int[] array,int bPrev,int ePrev ,int first,int end,int bNext,int eNext
			 ,int currProcess,int numberOfSteps,ThreadControl locki2)
	 {
		 resArray=array;
		 myArray=Arrays.copyOfRange(array,first,end+1);
		 currBegin=first;
		 currEnd= end;
		 this.currProcess=currProcess;
		 this.nextBegin=bNext;
		 this.nextEnd=eNext;
		 this.prevBegin=bPrev;
		 this.prevEnd=ePrev;
		 this.numberOfSteps=numberOfSteps; 
		 tControle= locki2;
	 }
	 
	 
	 public void run()
	 	// The heart of the thread, will follow the current pattern:
	 	// Sort array - Syncronise with other threads - Enter step loop
	 
	 
	 {
		int tempArray[]={-1};		 
		Arrays.sort(myArray);
		int temp=0;
		for(int i=currBegin;i<=currEnd;i++)
		 {
			 resArray[i]=myArray[temp]; // Copy sorted array in res array
			 temp++;
		 }
		
		System.out.println(Thread.currentThread().getName()+" created");
		
		try {
			tControle.synchronize();
		} catch (InterruptedException e) {
					
			e.printStackTrace();
		}
		
		for (int counter=0;counter< 2*numberOfSteps;counter++){
			// For each step follow this pattern:
			// Determine step parity - execute step and merge - synchronise with other threads
			// Write in final list- synchronise
			
			
			if(counter >= numberOfSteps ){
				tControle.threadStop--;	
				if(tControle.threadStop==0){ 	// Makes sure only the last thread prints the final list
					printList();
				}				
				return;
			}
			
			// Even Or odd step
			
			if(counter%2==0 ){
				try {
					tempArray=evenStep();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}	
			}
			else{
				try {
						tempArray=oddStep();
					} 
				
				catch (InterruptedException e) {
						e.printStackTrace();
					}				
			}
			
			// Sync
			try {
                tControle.synchronize();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
			
			// Write
			
			if (tempArray[0]!=-1){
				write(tempArray);}
			else{				
				System.out.println("fusion and writing not possible for "+ Thread.currentThread().getName());
				}
			
			// Sync
			try {
                tControle.synchronize();
            } catch (InterruptedException e) {
                e.printStackTrace();
				}			
		}

	 }

	
	 
	 public  void printList(){
		 // Prints final sorted list
		 
		 
		 
		 System.out.print("Sorted List: [");
		 for (int i=0 ; i<resArray.length;i++){
			 System.out.print(resArray[i]);
			 if (i!=resArray.length-1){
				 System.out.print(",");
			 }
		 }
		 System.out.println("]");	 
	 }
	 
	
	 
	 public int[] evenStep() throws InterruptedException{
		 	// Takes care of the even Step
		 	
	 		
	 		int error[]={-1};
	 		int lengthNext=(nextEnd-nextBegin)+1;
	 		int lengthPrev=(prevEnd-prevBegin)+1;
			if(currProcess==numberOfSteps-1)
			{
				if(currProcess%2==0) // Last thread cannot be even
				{	
					return error;
				}
				else
				{
					return merge(myArray,lengthPrev,1);	//left
				}
			}
			else if(currProcess%2==0)
			{
				int[] tempArray = new int[myArray.length];
				return merge(tempArray,lengthNext,0);//right
			}
			else
			{
				int[] tempArray = new int[myArray.length];
				return merge(tempArray,lengthPrev,1);	//left
			}
	 		
	 		
	 		
	 	}
	 	public int[] oddStep() throws InterruptedException{
	 		// Takes care of the odd Step
	 		
	 		
	 		int[] tempArray = new int[myArray.length];
	 		int[] error={-1};
	 		int lengthNext=(nextEnd-nextBegin)+1; // for left merge
	 		int lengthPrev=(prevEnd-prevBegin)+1; // for right merge	
			
			if(currProcess==0)// First thread is invalid for this step
			{
				return error;
			}
			else if(currProcess==numberOfSteps-1)
			{
				if(currProcess%2==1) // Last thread cannot be odd
				{
					return error;
				}
				else
				{
					return merge(tempArray,lengthPrev,1);	//left
				}
			}
			else if(currProcess%2==1)
			{
				return merge(tempArray,lengthNext,0);//right
			}
			else if(currProcess%2==0 )
			{
				return merge(tempArray,lengthPrev,1);	//left
			}			
	 		return error; // Any other case is invalid 		
	 	}

	 	public int[] merge(int[]tempArray,int neighboorLength,int rightLeft){
	 		// merge the adjacent blocks by creating a array with the to blocks then sorting it
	 		// if rightLeft=0 ----> right merge
	 		// if rightLeft=1 ----> left merge
	 		// returns new sorted array
	 		
	 		
	 		
	 		
	 		System.out.println(Thread.currentThread().getName()+" is merging.");
	 		int nextLength=neighboorLength;
	 		int length =myArray.length+nextLength;
	 		int[] tempArrayCombi=new int[length];
	 		System.arraycopy(myArray,0, tempArrayCombi,0,myArray.length);
	 		
	 		
	 		
	 		if (rightLeft==0){
	 			System.arraycopy(resArray, nextBegin, tempArrayCombi, myArray.length, nextLength);
	 		}
	 		else if (rightLeft==1){
				System.arraycopy(resArray, prevBegin, tempArrayCombi, myArray.length, nextLength);			
	 		}
	 		
	 		Arrays.sort(tempArrayCombi);
	 		
			for(int i=0;i<tempArray.length;i++)	// copy the sorted array back to temp
			{
				if (rightLeft==0){
					tempArray[i]=tempArrayCombi[i];
				
				}
				else if (rightLeft==1){
					tempArray[i]=tempArrayCombi[nextLength+i];
		
				}		
			}
			myArray=Arrays.copyOfRange(tempArray,0,tempArray.length);	// new array kept in myArray
			
			return tempArray; 		
	 	}
	 	
	 	public void write(int []tempArray2){
	 		//Writing in the final list 
	 		
	 	
	 		
	 		int temp=0;
	 		System.out.println("Thread " +Thread.currentThread().getName()+" is writing");
	 		for(int i=currBegin;i<currEnd+1;i++)
	 		{
	 			resArray[i]=tempArray2[temp];
	 			temp++;
	 		}
	 	}
	 		 	
	 	public boolean Sorted(){
	 		// Checks if the array is sorted 
	 		// Returns boolean
	 		
	 		int prec=0;
	 		for (int value=0;value<resArray.length;value++){
	 			if (value<prec){
	 				return false;
	 			}
	 			prec=value;
	 			
	 		}
	 		return true;		
	 	}
	 	
}	 	
	
	 
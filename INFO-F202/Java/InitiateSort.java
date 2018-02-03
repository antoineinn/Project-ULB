//Antoine Innocent BA2 Informatique
//Matricule: 000394700



package packaging;


import java.util.Scanner;

import packaging.Sort;
import packaging.ThreadControl;

public class InitiateSort 
{

	public static void main(String[] args) throws InterruptedException
	{
		
		Scanner sc= new Scanner(System.in);
		System.out.println("Please enter the number of elements (n):");
		int numElements  =sc.nextInt();
			
		int array[]=InitArray(numElements);
		System.out.println("Enter the number of processus:");

		sc = new Scanner(System.in);
		int process= sc.nextInt();
			
		System.out.println("----Initial List----");
		System.out.println("");
		
		System.out.print("[");
		for (int i=0 ; i<array.length;i++){			//Print Initial list
			 System.out.print(array[i]);
			 if (i!=array.length-1){
				 System.out.print(",");
			 }
		 }
		System.out.println("]");
		
		System.out.println("");
		
		System.out.println("###[Sorting Initiated]###");
		initiateThread(array, process);
	
	}
		
	
	
	private static int[] InitArray(int numElements){
		//Generates random array of 'numElements' Elements
		//Returns array of int
		
		
		
		int array[]=new int[numElements];
		int maxValue=80;	//Max value of list element
		for (int i=0;i<numElements;i++){
			array[i]=(int)(Math.random()*maxValue);	// Randomly choose an int 
		}
		return array;	
	}
	
	
	
	private static void initiateThread(int[] array,int process) throws InterruptedException{
		//Create every block and assign it to each thread
		
			
		int floorSize = (int)Math.floor((double)array.length/process);
		int ceilSize=(int)Math.ceil((double)array.length/process); 
		int ceilProcess=(array.length%process); // Number of thread with ceilSize elements
		int floorProcess=process-ceilProcess;	// Number of thread with floorSize elements
		
		int currBegin=0;
		int currEnd=0;
		int nextBegin=0;	// The limits of each blocks for transfering
		int nextEnd=0;
		int prevBegin=0;
		int prevEnd=0;

		int temp=0;
		int counter=0;
		ThreadControl locki= new ThreadControl(process);	// Creation of global lock for threads
		
		while (counter<process)
		{
			
			// Here we assign the different block limits to pass for each thread
			
			
			
			if(counter==0)
			{
				if(ceilProcess>floorProcess)
				{
				
					temp=floorProcess;
					currEnd=ceilSize-1;
					nextEnd=currEnd+floorSize;
				}	
				else
				{
					temp=ceilProcess;					
					currEnd=floorSize-1;
					nextEnd=currEnd+ceilSize;
					
				}
				nextBegin=currEnd+1;	
			}
			else
			{
				prevBegin=currBegin;
				prevEnd=currEnd;
				currBegin=new Integer(nextBegin);
				currEnd=new Integer(nextEnd);
				nextBegin=currEnd+1;
			    
				if(counter%2==0 && temp>0)
				{
					if(ceilProcess>floorProcess)
					{
						nextEnd=currEnd+floorSize;
					}
					else
					{
						nextEnd=currEnd+ceilSize;
					}
				}
				
				
			    else 
				
			    {
			    	if(counter%2==1 && temp>0){
			    		temp--;}
			    	
					if(ceilProcess>floorProcess)
					{
						nextEnd=currEnd+ceilSize;
					}
					else
					{
						nextEnd=currEnd+floorSize;
					}
				}}	
				
			
	
		
			Sort t1 =new Sort(array,prevBegin,prevEnd,currBegin,currEnd,
					nextBegin,nextEnd,counter,process,locki);	//Thread function 
			
			t1.start();	
			
			counter++;
		}
	
	}
	


	
}
#!/bin/bash
#Antoine Innocent
#Ba2 Informatique
#000394700

while read line
do
	echo $line >> "$line.txt" # Iterate in source text file and creates file for each file
							  # Each filename is the line 

done < p1_quotes



for var in "$@"	# In current directory
do
	
	mkdir $var 

	if ! grep -i -q -w -r $var --exclude="p1_quotes" ; then	

		# Checks if the given arguments exist (not case sensitive, in current directory, no return text, without text output) 
    	
		for filename in *.txt; do # Iterate in all txt files in current directory
			
			if [ "$filename" != "p1_quotes" ];then
				echo "Chuck Norris" > "$filename"	# Overwrites the current name with Chuck Norris
				
			fi
			
		done
		break
			
	else
		 find .  -iname "*$var*" -exec cp {} $var \;	# Copy files in new directory
		
	fi
done

		
	





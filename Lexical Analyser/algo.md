## Algorithm

* <b>Step 1:</b> Start

* <b>Step 2:</b> Read a character from the input file
* <b>Step 3:</b> If it is an Operator goto step 4 else goto step 7 
* <b>Step 4:</b> Check if it is '/' and the next character is '/' or '*' If yes goto step 5 else goto step 6
* <b>Step 5:</b> Ignore all the character using a while loop until the characters '//' or '*/' is encountered respectively and in order.
* <b>Step 6:</b> Print the character as an operator
* <b>Step 7:</b> Check if it is a Special character if yes print it as special character
* <b>Step 8:</b> Check if it is a digit if yes print it as a digit
* <b>Step 9:</b> Check if it is an alphabet if true goto step 10 else goto step 12
* <b>Step 10:</b> Read the character following using a while loop into a temporary array until a delimiter is encountered ( space )
* <b>Step 11:</b>Check if the string read is a valid keyword If true print it as a keyword else as an Identifier.
* <b>Step 12:</b> Increment the variable tracking the current line number.
* <b>Step 13:</b> Do step 2 to step 12 until the end of file is encountered.
* <b>Step 14:</b> Stop

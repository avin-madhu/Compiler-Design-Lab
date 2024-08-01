## Algorithm for Lexical Analyser


* Step 1: Start

* Step 2: Read a character from the Input File

* Step 3: If it is an Operator goto step 4 else goto step 8
* Step 4: Check if the character read is '/' and the next character is '/' (which means it is a single line comments) or the next character is a '*' (which means it's a multi line comments )
* Step 5: If step 4 is True goto step 6 else goto step 7
* Step 6: Ignore all characters with a while loop until a '*/' characters are encountered in order.
* Step 7: Print the character as an operator.
* Step 8: If it is a Special Symbol print it as a Special Symbol else goto step 9
* Step 9: If it is a digit print it as a digit else goto step 10
* Step 10: If it is a alphabet goto step 11 else step 12
* Step 11: Read the character and the characters that follows that into an character array until a delimiter (Space) is occured into an array.
* Step 12: Check if the string that is read is in the array of valid keywords
* Step 13: If Step 12 is true print it as a keyword else print it as an Identifier.
* Step 14: Increment the variable that tracks line number
* Step 15: Repeat Step 2 to Step 14 until EOF is encountered in the input file.
* Step 16: Stop

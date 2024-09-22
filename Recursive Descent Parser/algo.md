## Algorithm


* <b>Step 1:</b> Start.
* <b>Step 2:</b> Initialize an index i to track the current character in the input string.
* <b>Step 3:</b> Call the function E() to begin parsing from the start symbol.
* <b>Step 4:</b> Inside E(), call T() to process the T non-terminal.
* <b>Step 5:</b> In T(), call F() to process the F non-terminal.
  -  **Step 5.1:** If the current character is '(', call E() recursively and expect a closing ')'.
  - <b>Step 5.2:</b>  Else, if the current character is an identifier (alphabetic), accept it and move to the next character.
  - <b>Step 5.3:</b> If neither condition is met, reject the string.
* <b>Step 6:</b>  After processing F(), call TP() to check for any further * operator followed by another F(). Repeat this step recursively if needed. If no * is found, accept the empty production (@).
* <b>Step 7:</b>  After processing T(), call EP() to check for any further + operator followed by another T(). Repeat this step recursively if needed. If no + is found, accept the empty production (@).
* <b>Step 8:</b>  After E() finishes, check if the entire input has been consumed (i.e., input[i] == '\0').
  - <b>Step 8.1:</b> If yes, accept the string.
  - <b>Step 8.2:</b>  If not, reject the string.
* <b>Step 9:</b>  Stop.
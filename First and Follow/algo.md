## Algorithm

### First ( )

* <b>Step 1:</b> Start

* <b>Step 2:</b> Check if the character is lowercase or it is an Epsilon.
* <b>Step 3:</b> If step 1 is true stop else continue
* <b>Step 4:</b> For any character of the start of the LHS that matches with the input character do step 5 to step  on the first character of it's RHS
* <b>Step 5:</b> If it is an epsilon add it to the result
* <b>Step 6:</b> If it is the same stop
* <b>Step 7:</b> If it is lowercase add it to the result set
* <b>Step 8:</b> If it is uppercase find the first of that character.
* <b>Step 9:</b> stop

### Follow ( )
* <b>Step 1:</b>If the input character is the first non-terminal of the production add `'$'` to te list.

* <b>Step 2:</b> For any character on the LHS of the productions that matches with the input character do Step 3 and Step 4
* <b>Step 3:</b> If the next character is end of line find the `follow()` and the non-terminal on it's LHS is not the same find the `follow()` of that non-terminal
* <b>Step 4:</b> If the next character is not the end of line find the `first()` of that character.
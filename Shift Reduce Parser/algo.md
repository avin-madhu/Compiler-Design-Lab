## Algorithm

* **Step 1:** Start.
* **Step 2:** Display the given grammar:
  - `E -> E+E`
  - `E -> E*E`
  - `E -> (E)`
  - `E -> id`
* **Step 3:** Accept the input string from the user and store it in the `input_string`.
* **Step 4:** Initialize the stack as empty and set the action to `"SHIFT ->"`.
* **Step 5:** Display the headers: "Stack", "Input", and "Action".
* **Step 6:** For each character in the `input_string` (loop through the input string):
  - **Step 6.1:** If the current character and the next character are `'i'` and `'d'`, respectively:
    - Push `'id'` to the stack.
    - Mark these characters as processed by setting them to spaces in the input string.
    - Display the current stack, input string, and action (`SHIFT -> id`).
    - Call the `check()` function to reduce.
  - **Step 6.2:** Otherwise:
    - Push the current character to the stack.
    - Mark it as processed by setting it to a space in the input string.
    - Display the current stack, input string, and action (`SHIFT -> character`).
    - Call the `check()` function to reduce.
* **Step 7:** In the `check()` function, attempt reductions:
  - **Step 7.1:** If the stack contains `'id'`, replace it with `E` and display the action (`REDUCE TO E`).
  - **Step 7.2:** If the stack contains the production `E + E`, replace it with `E` and display the action (`REDUCE TO E`).
  - **Step 7.3:** If the stack contains the production `E * E`, replace it with `E` and display the action (`REDUCE TO E`).
  - **Step 7.4:** If the stack contains the production `( E )`, replace it with `E` and display the action (`REDUCE TO E`).
* **Step 8:** Repeat Steps 6–7 until all input characters are processed.
* **Step 9:** If the input string is fully reduced to `E`, accept the input string.
* **Step 10:** Stop.

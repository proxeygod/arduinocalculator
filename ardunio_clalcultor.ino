#include <Keypad.h>
#include <LiquidCrystal.h>

// Initialize the LCD (using 8-bit mode; 16x2 display)
LiquidCrystal lcd(22, 23, 24, 25, 26, 27, 28, 29, 30, 31);

// Define keypad configuration (4x4 matrix)
// Physical layout:
//  +-----+-----+-----+-----+
//  |  1  |  2  |  3  |  A  |
//  +-----+-----+-----+-----+
//  |  4  |  5  |  6  |  B  |
//  +-----+-----+-----+-----+
//  |  7  |  8  |  9  |  C  |
//  +-----+-----+-----+-----+
//  |  *  |  0  |  #  |  D  |
//  +-----+-----+-----+-----+
//
// Logical mapping in the code:
// • Numeric keys (0–9) build the expression.
// • Keys A, B, C, D serve as operators and are displayed as:
//     A → +, B → –, C → *, D → /
// • '#' is the Enter key which evaluates the expression.
// • '*' always acts as a backspace to delete the last character.

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Two strings are used:
// • inputCalc holds the raw input (operators stored as letters: A, B, C, D)
// • inputDisplay holds the string shown on the LCD (with A–D converted to +, -, *, /)
String inputCalc = "";
String inputDisplay = "";

void setup() {
  lcd.begin(16, 2);         // Initialize the 16x2 LCD
  lcd.print("Calc Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // When Enter ('#') is pressed, evaluate the expression.
    if (key == '#') {
      if (inputCalc.length() > 0) {
        float result = evaluateExpression(inputCalc);
        String resStr = String(result);  // convert result to string for alignment
        int resTotalWidth = resStr.length() + 1;  // answer width plus one equals sign
      
        // Determine maximum number of characters allowed for the expression on row0.
        int maxExpLen = 16;  // we use full row for expression
        String dispExp = inputDisplay;
        if (dispExp.length() > maxExpLen) {
          dispExp = dispExp.substring(dispExp.length() - maxExpLen);
        }
      
        // Clear and print final screen.
        lcd.clear();
        // Row 0 shows the typed (trimmed) expression.
        lcd.setCursor(0, 0);
        lcd.print(dispExp);
        // Row 1: print the answer right aligned. 
        // Calculate the starting column so that total width (equals sign + answer string) fits to the right.
        int answerStartColumn = 16 - resTotalWidth;
        lcd.setCursor(answerStartColumn, 1);
        lcd.print("=");
        lcd.print(resStr);
      
        delay(1500);  // Hold the display for 1.5 seconds
      
        // Clear all input for the next calculation.
        inputCalc = "";
        inputDisplay = "";
        lcd.clear();
      }
    }
    // Clear/backspace key '*' always deletes one character.
    else if (key == '*') {
      if (inputCalc.length() > 0) {
        inputCalc.remove(inputCalc.length() - 1);
        inputDisplay.remove(inputDisplay.length() - 1);
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      if (inputDisplay.length() <= 16) {
        lcd.print(inputDisplay);
      } else {
        lcd.print(inputDisplay.substring(inputDisplay.length() - 16));
      }
    }
    // For any other key: append it to the expression.
    else {
      // For operator keys (A, B, C, D), add their raw value to inputCalc
      // and append the corresponding operator symbol to inputDisplay.
      if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
        inputCalc += key;
        char opSymbol = convertOperator(key);  // e.g., A becomes '+'
        inputDisplay += opSymbol;
      }
      // For numeric keys (and the decimal point, if desired)
      else {
        inputCalc += key;
        inputDisplay += key;
      }
      
      lcd.clear();
      lcd.setCursor(0, 0);
      if (inputDisplay.length() <= 16) {
        lcd.print(inputDisplay);
      } else {
        lcd.print(inputDisplay.substring(inputDisplay.length() - 16));
      }
    }
  }
}

//--------------------------------------------------
// evaluateExpression()
// Parses the arithmetic expression (with operators as A, B, C, D)
// stored in inputCalc and returns the calculated result as a float.
float evaluateExpression(String expr) {
  float result = 0;
  char operatorSymbol = '\0';
  String currentNumber = "";
  
  for (int i = 0; i < expr.length(); i++) {
    char c = expr.charAt(i);
    if (isDigit(c) || c == '.') {
      currentNumber += c;
    } 
    else if (c == 'A' || c == 'B' || c == 'C' || c == 'D') {
      if (currentNumber != "") {
        if (operatorSymbol == '\0') {
          result = currentNumber.toFloat();
        } else {
          result = calculate(result, currentNumber.toFloat(), operatorSymbol);
        }
      }
      operatorSymbol = convertOperator(c);
      currentNumber = "";
    }
  }
  
  if (currentNumber != "") {
    result = calculate(result, currentNumber.toFloat(), operatorSymbol);
  }
  
  return result;
}

//--------------------------------------------------
// convertOperator()
// Maps the operator keys (A, B, C, D) to their corresponding mathematical symbols.
char convertOperator(char op) {
  switch (op) {
    case 'A': return '+';
    case 'B': return '-';
    case 'C': return '*';  // Alternatively, you could use '×'
    case 'D': return '/';  // Alternatively, you might use '÷'
    default:  return op;
  }
}

//--------------------------------------------------
// calculate()
// Performs arithmetic on num1 and num2 using the provided operator.
float calculate(float num1, float num2, char op) {
  switch (op) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return (num2 != 0 ? num1 / num2 : 0);  // Avoid division by zero.
    default:  return num2;
  }
}

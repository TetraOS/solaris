# Solaris Window Manager Code Style Guide

This document outlines the preferred code style for the Solaris Window Manager repository, primarily written in C++. Adherence to these guidelines ensures consistency and readability across the codebase.

## 1. Indentation

- Use tabs for indentation, with each tab equivalent to 2 spaces.
- Ensure consistent indentation levels to clearly define block structures.

Example:

```cpp
void someFunction() {
  if (condition) {
    // Indented block
  } else {
    // Another indented block
  }
}
```

## 2. Line Length and Formatting

- Limit lines to 100 columns.
- Break long statements into readable chunks.
- Maintain consistent spacing around keywords, operators, and punctuation.
- Avoid trailing whitespace at the end of lines.

Example:

```cpp
int result = functionWithLongName(argument1, argument2, argument3
                                            argument4, argument5);
```

## 3. Braces and Spaces

- Place opening braces on the same line for function and control statement blocks.
- Use a new line for closing braces.
- Add spaces after most keywords but not around parentheses in expressions.
- Ensure proper spacing around operators and structure member operators.
- Do not leave trailing whitespace at the ends of lines.

Example: 

```cpp
if (condition) {
  doThis();
} else {
  doThat();
}
```

## 4. Naming

- Use descriptive names for variables, functions, classes, and namespaces.
- Follow camelCase naming convention for variables and functions.
- Follow PascalCase naming convention for class names.
- Use namespace names that are clear and concise, avoiding abbreviations when possible.

Example:

```cpp
class WindowManager {
public:
  void resizeWindow(int width, int height);
};

namespace solaris {
  void launchApplication(const std::string& appName);
}
```

## 5. Typedefs and Using Declarations

- Use using declarations for type aliases.
- Prefer type aliases over typedef.
- Use descriptive names for type aliases.

Example:

```cpp
using UserId = int;
```

## 6. Functions

- Keep functions short, focusing on doing one thing well.
- Limit functions to one or two screenfuls of text.
- Minimize complexity and indentation levels.
- Use helper functions with descriptive names for complex operations.
- Separate functions with one blank line in source files.

Example:

```cpp
void performTask(int taskID) {
  // Implementation details
}
```

## 7. Commenting

- Write comments to explain **WHAT** the code does, not **HOW** it works.
- Place comments above the code they describe.
- Use Doxygen-style comments for documenting classes, methods, and namespaces.
- Include parameter descriptions in function and method comments.
- Comment data declarations to explain their purpose and usage.

Example:

```cpp
/**
 * @brief Calculate the sum of two integers.
 *
 * @param x The first integer.
 * @param y The second integer.
 * @return The sum of x and y.
 */
int calculateSum(int x, int y) {
  return x + y;
}
```

Adhering to these guidelines ensures code consistency, readability, and maintainability across the Solaris Window Manager repository.

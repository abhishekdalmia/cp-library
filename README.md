# CP Library

A collection of competitive programming templates and utilities.

## Makefile Usage

### Basic Commands

- **Build the program:**

  ```bash
  make
  ```

  Compiles `main.cpp` to `main.out` with standard flags (`-g -std=c++11`)

- **Build with debug mode:**

  ```bash
  make DEBUG=1
  ```

  Compiles with `-DDEBUG` flag, enabling debug statements

- **Clean build artifacts:**

  ```bash
  make clean
  ```

  Removes the compiled `main.out` file

- **Run the program:**

  ```bash
  make run
  ```

  Executes `./main.out`

- **Full rebuild and run:**
  ```bash
  make final
  ```
  Runs `clean`, `main`, and `run` in sequence

### Debug Statements

The `skeleton.cpp` template includes a `dbg` macro that works like `cout` but only outputs when compiled with `DEBUG=1`.

**Usage in your code:**

```cpp
int n = 5;
dbg << "n = " << n << endl;
dbg << "Processing element " << i << "\n";
```

**Compilation modes:**

- `make` - debug statements have no effect (optimized away)
- `make DEBUG=1` - debug statements print normally

This allows you to leave debug statements in your code without affecting performance or output during normal compilation.

# Basic Math for DSA - Complete Notes

## Table of Contents
1. [Digit Extraction](#digit-extraction)
2. [Common Digit Problems](#common-digit-problems)
3. [Divisors and Prime Numbers](#divisors-and-prime-numbers)
4. [GCD/HCF Algorithms](#gcdhcf-algorithms)
5. [Quick Reference](#quick-reference)

---

## Digit Extraction

**Core Concept:** Foundation for solving many mathematical problems in DSA.

### Basic Operations

#### Get Last Digit
```cpp
int n = 12345;
int lastDigit = n % 10;  // lastDigit = 5
```

#### Remove Last Digit
```cpp
int n = 12345;
n = n / 10;  // n becomes 1234
```

### Complete Extraction Loop

```cpp
int n = 7789;
while (n > 0) {
    int lastDigit = n % 10;  // Extract last digit
    // Perform operations with lastDigit
    cout << lastDigit << " ";  // Output: 9 8 7 7
    n = n / 10;                // Remove last digit
}
```

### Time Complexity Analysis

**Why O(log₁₀ N)?**

For a number with `d` digits:
- Number of iterations = number of digits
- A number `N` has `⌊log₁₀(N)⌋ + 1` digits

Example:
```
N = 12345 (5 digits)
log₁₀(12345) = 4.09 → ⌊4.09⌋ + 1 = 5 digits ✓
```

**Time Complexity:** `O(log₁₀ N)` or simply `O(log N)`

---

## Common Digit Problems

### 1. Count Digits

#### Method 1: Loop Counter
```cpp
int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n = n / 10;
    }
    return count;
}
```

**Time Complexity:** O(log₁₀ N)

#### Method 2: Mathematical Formula
```cpp
int countDigits(int n) {
    if (n == 0) return 1;
    return (int)(log10(n) + 1);
}
```

**Time Complexity:** O(1)

**Examples:**
```cpp
countDigits(12345);  // Returns 5
countDigits(7);      // Returns 1
countDigits(0);      // Returns 1
```

---

### 2. Reverse a Number

#### Algorithm
```cpp
int reverseNumber(int n) {
    int revNum = 0;
    
    while (n > 0) {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;  // Build reverse number
        n = n / 10;
    }
    
    return revNum;
}
```

**Step-by-step for n = 7789:**
```
Iteration 1: lastDigit = 9, revNum = 0 * 10 + 9 = 9,    n = 778
Iteration 2: lastDigit = 8, revNum = 9 * 10 + 8 = 98,   n = 77
Iteration 3: lastDigit = 7, revNum = 98 * 10 + 7 = 987, n = 7
Iteration 4: lastDigit = 7, revNum = 987 * 10 + 7 = 9877, n = 0
Result: 9877
```

**Time Complexity:** O(log₁₀ N)  
**Space Complexity:** O(1)

---

### 3. Check Palindrome

A number is a palindrome if it reads the same forwards and backwards (e.g., 121, 12321).

#### Algorithm
```cpp
bool isPalindrome(int n) {
    int original = n;  // IMPORTANT: Store original before modifying
    int revNum = 0;
    
    while (n > 0) {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
    }
    
    return (original == revNum);
}
```

**⚠️ Critical Tip:** Always store the original number in a separate variable before the loop, as `n` becomes `0` after extraction!

**Examples:**
```cpp
isPalindrome(121);    // true
isPalindrome(123);    // false
isPalindrome(12321);  // true
isPalindrome(1);      // true
```

**Time Complexity:** O(log₁₀ N)  
**Space Complexity:** O(1)

---

### 4. Armstrong Number

**Definition:** A number is an Armstrong number if the sum of cubes of its digits equals the number itself.

**Examples:**
- 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓
- 371 = 3³ + 7³ + 1³ = 27 + 343 + 1 = 371 ✓
- 123 = 1³ + 2³ + 3³ = 1 + 8 + 27 = 36 ✗

#### Algorithm
```cpp
bool isArmstrong(int n) {
    int original = n;
    int sum = 0;
    
    while (n > 0) {
        int lastDigit = n % 10;
        sum += (lastDigit * lastDigit * lastDigit);  // Cube of digit
        n = n / 10;
    }
    
    return (original == sum);
}
```

**Step-by-step for n = 153:**
```
Iteration 1: digit = 3, sum = 0 + 3³ = 27
Iteration 2: digit = 5, sum = 27 + 5³ = 152
Iteration 3: digit = 1, sum = 152 + 1³ = 153
153 == 153 → true ✓
```

**Time Complexity:** O(log₁₀ N)  
**Space Complexity:** O(1)

#### Generalized Armstrong Number
For numbers with `k` digits, each digit should be raised to power `k`:

```cpp
bool isArmstrongGeneral(int n) {
    int original = n;
    int k = (int)(log10(n) + 1);  // Count digits
    int sum = 0;
    
    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, k);
        n = n / 10;
    }
    
    return (original == sum);
}
```

**Examples:**
- 9474 = 9⁴ + 4⁴ + 7⁴ + 4⁴ = 6561 + 256 + 2401 + 256 = 9474 ✓

---

## Divisors and Prime Numbers

### 1. Print All Divisors

A divisor of `n` is a number that divides `n` completely (remainder = 0).

#### Method 1: Brute Force

```cpp
void printDivisors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
}
```

**Example for n = 36:**
```
Output: 1 2 3 4 6 9 12 18 36
```

**Time Complexity:** O(N)  
**Space Complexity:** O(1)

---

#### Method 2: Optimized (Square Root Method)

**Key Insight:** Divisors come in pairs!

For n = 36:
```
1 × 36 = 36  →  Divisors: 1, 36
2 × 18 = 36  →  Divisors: 2, 18
3 × 12 = 36  →  Divisors: 3, 12
4 × 9 = 36   →  Divisors: 4, 9
6 × 6 = 36   →  Divisor: 6 (only once!)
```

Notice: After √36 = 6, pairs start repeating in reverse.

```cpp
void printDivisorsOptimized(int n) {
    for (int i = 1; i * i <= n; i++) {  // Loop until √n
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) {  // Avoid printing square root twice
                cout << n / i << " ";
            }
        }
    }
}
```

**Example for n = 36:**
```
i = 1: Print 1 and 36
i = 2: Print 2 and 18
i = 3: Print 3 and 12
i = 4: Print 4 and 9
i = 6: Print 6 (skip 36/6 = 6, already printed)
Output: 1 36 2 18 3 12 4 9 6
```

**⚠️ Efficiency Tip:** Use `i * i <= n` instead of `i <= sqrt(n)` to avoid repeated square root calculations.

**Time Complexity:** O(√N)  
**Space Complexity:** O(1)

#### Sorted Output Version
```cpp
void printDivisorsSorted(int n) {
    vector<int> divisors;
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    
    sort(divisors.begin(), divisors.end());
    
    for (int d : divisors) {
        cout << d << " ";
    }
}
```

**Time Complexity:** O(√N) + O(k log k) where k = number of divisors  
**Space Complexity:** O(k)

---

### 2. Check for Prime Number

**Definition:** A prime number has exactly **two factors**: 1 and itself.

**Examples:**
- Prime: 2, 3, 5, 7, 11, 13, 17, 19, 23...
- Not Prime: 1 (only 1 factor), 4 (factors: 1, 2, 4), 6 (factors: 1, 2, 3, 6)

#### Method 1: Brute Force
```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    
    return (count == 2);
}
```

**Time Complexity:** O(N)

---

#### Method 2: Optimized (Square Root Method)
```cpp
bool isPrimeOptimized(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check for divisors from 5 to √n
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}
```

**Why this works:**
- All primes > 3 are of the form `6k ± 1`
- We check divisibility by 2 and 3 first
- Then check `6k - 1` and `6k + 1` (i.e., i and i+2)

**Time Complexity:** O(√N)  
**Space Complexity:** O(1)

#### Simple Square Root Method
```cpp
bool isPrimeSimple(int n) {
    if (n <= 1) return false;
    
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {  // If i and n/i are different
                count++;
            }
        }
    }
    
    return (count == 2);
}
```

**Time Complexity:** O(√N)

---

### Count Factors (Divisors)

```cpp
int countDivisors(int n) {
    int count = 0;
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {
                count++;
            }
        }
    }
    
    return count;
}
```

**Examples:**
```cpp
countDivisors(36);  // Returns 9 (divisors: 1,2,3,4,6,9,12,18,36)
countDivisors(7);   // Returns 2 (divisors: 1,7) - Prime number
countDivisors(12);  // Returns 6 (divisors: 1,2,3,4,6,12)
```

**Time Complexity:** O(√N)

---

## GCD/HCF Algorithms

**GCD (Greatest Common Divisor)** or **HCF (Highest Common Factor)**: The largest number that divides both numbers.

**Examples:**
- gcd(20, 40) = 20
- gcd(9, 12) = 3
- gcd(7, 13) = 1 (coprime numbers)

---

### Method 1: Brute Force

```cpp
int gcdBruteForce(int a, int b) {
    int gcd = 1;
    
    // Loop from min(a, b) down to 1
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break;  // First common divisor is the greatest
        }
    }
    
    return gcd;
}
```

**Time Complexity:** O(min(a, b))  
**Space Complexity:** O(1)

---

### Method 2: Euclidean Algorithm (Subtraction)

**Key Principle:**
```
gcd(a, b) = gcd(a - b, b)  where a > b
```

**Logic:** The GCD of two numbers doesn't change if we subtract the smaller from the larger.

```cpp
int gcdEuclidean(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    
    // When one becomes 0, the other is the GCD
    return (a == 0) ? b : a;
}
```

**Example: gcd(52, 10)**
```
Step 1: a=52, b=10 → a > b → a = 52-10 = 42
Step 2: a=42, b=10 → a > b → a = 42-10 = 32
Step 3: a=32, b=10 → a > b → a = 32-10 = 22
Step 4: a=22, b=10 → a > b → a = 22-10 = 12
Step 5: a=12, b=10 → a > b → a = 12-10 = 2
Step 6: a=2, b=10  → b > a → b = 10-2 = 8
Step 7: a=2, b=8   → b > a → b = 8-2 = 6
Step 8: a=2, b=6   → b > a → b = 6-2 = 4
Step 9: a=2, b=4   → b > a → b = 4-2 = 2
Step 10: a=2, b=2  → a == b → a = 2-2 = 0
Result: b = 2
```

**Time Complexity:** O(min(a, b)) in worst case

---

### Method 3: Euclidean Algorithm (Modulo) ⭐ **Best Method**

**Key Principle:**
```
gcd(a, b) = gcd(a % b, b)  where a > b
```

**Why modulo is better:** Instead of repeated subtraction, we can use modulo to jump directly to the remainder.

```cpp
int gcdOptimal(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    
    return (a == 0) ? b : a;
}
```

**Example: gcd(52, 10)**
```
Step 1: a=52, b=10 → a > b → a = 52 % 10 = 2
Step 2: a=2, b=10  → b > a → b = 10 % 2 = 0
Step 3: b=0 → return a=2
Result: 2
```

**Comparison:**
- Subtraction method: 10 steps
- Modulo method: 2 steps ⚡

#### Cleaner Version (STL Alternative)
```cpp
int gcdOptimal(int a, int b) {
    if (b == 0) return a;
    return gcdOptimal(b, a % b);
}

// Or use C++ STL
#include <algorithm>
int result = __gcd(a, b);  // Built-in function
```

**Time Complexity:** O(log φ(min(a, b))) where φ ≈ 1.618 (Golden Ratio)
- In practice: **O(log(min(a, b)))**

**Space Complexity:** 
- Iterative: O(1)
- Recursive: O(log(min(a, b))) due to call stack

---

### LCM (Least Common Multiple)

**Formula:**
```
LCM(a, b) = (a × b) / GCD(a, b)
```

```cpp
int lcm(int a, int b) {
    return (a * b) / gcdOptimal(a, b);
}
```

**⚠️ Overflow Prevention:**
```cpp
long long lcm(int a, int b) {
    return ((long long)a * b) / gcdOptimal(a, b);
}

// Or better:
long long lcm(int a, int b) {
    return (a / gcdOptimal(a, b)) * b;  // Divide first to avoid overflow
}
```

**Examples:**
```cpp
lcm(4, 6) = (4 × 6) / gcd(4,6) = 24 / 2 = 12
lcm(3, 7) = (3 × 7) / gcd(3,7) = 21 / 1 = 21
```

---

## Quick Reference

### Time Complexity Summary

| Operation | Brute Force | Optimized | Best |
|-----------|-------------|-----------|------|
| Count Digits | O(log N) | O(1) with formula | O(1) |
| Reverse Number | O(log N) | - | O(log N) |
| Check Palindrome | O(log N) | - | O(log N) |
| Armstrong Number | O(log N) | - | O(log N) |
| Print Divisors | O(N) | O(√N) | O(√N) |
| Check Prime | O(N) | O(√N) | O(√N) |
| GCD | O(min(a,b)) | O(log(min(a,b))) | O(log(min(a,b))) |

### Key Formulas

```cpp
// Count digits
digits = (int)(log10(n) + 1)

// Reverse number building
revNum = (revNum * 10) + lastDigit

// Check divisor pair
if (i * i <= n) {
    // i and n/i are both divisors
}

// GCD-LCM relationship
LCM(a, b) × GCD(a, b) = a × b
```

### Important Patterns

#### Digit Extraction Pattern
```cpp
while (n > 0) {
    int digit = n % 10;  // Get last digit
    // Process digit
    n = n / 10;          // Remove last digit
}
```

#### Square Root Optimization Pattern
```cpp
for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        // i is a divisor
        // n/i is also a divisor (if different from i)
    }
}
```

#### Euclidean GCD Pattern
```cpp
while (a > 0 && b > 0) {
    if (a > b) a = a % b;
    else b = b % a;
}
return (a == 0) ? b : a;
```

---

## Practice Problems

### Beginner
1. Count digits in a number
2. Check if a number is palindrome
3. Find sum of digits
4. Check if number is Armstrong

### Intermediate
5. Print all divisors in sorted order
6. Check if number is prime
7. Find GCD of two numbers
8. Count prime numbers up to N (Sieve of Eratosthenes)

### Advanced
9. Find all prime factors of a number
10. Count divisors in O(√N)
11. Find GCD of array of numbers
12. Find smallest number with exactly N divisors

---

## Common Mistakes to Avoid

❌ Forgetting to store original number before modifying it  
❌ Using `sqrt(n)` in loop condition (calculate once or use `i*i <= n`)  
❌ Not handling edge cases (n = 0, n = 1, negative numbers)  
❌ Integer overflow when calculating LCM  
❌ Checking divisibility without considering number 1  
❌ Not optimizing prime check to O(√N)  
❌ Counting square root twice in divisor count

---

## Pro Tips

💡 **Always use `i * i <= n` instead of `i <= sqrt(n)` for efficiency**  
💡 **Store original number before modification in digit problems**  
💡 **For LCM calculation, divide first to prevent overflow**  
💡 **Use built-in `__gcd(a, b)` in competitive programming**  
💡 **Remember: All primes > 3 are of form 6k ± 1**  
💡 **Euclidean algorithm with modulo is O(log n), very fast!**  
💡 **Count divisors pattern appears in many problems**

---

## Useful Code Snippets

### All-in-One Digit Operations
```cpp
struct DigitInfo {
    int count;
    int sum;
    int reverse;
    bool isPalindrome;
    bool isArmstrong;
};

DigitInfo analyzeNumber(int n) {
    DigitInfo info;
    int original = n;
    info.reverse = 0;
    info.sum = 0;
    info.count = 0;
    
    while (n > 0) {
        int digit = n % 10;
        info.count++;
        info.sum += digit;
        info.reverse = info.reverse * 10 + digit;
        n /= 10;
    }
    
    info.isPalindrome = (original == info.reverse);
    
    // Check Armstrong
    int temp = original;
    int armSum = 0;
    while (temp > 0) {
        int d = temp % 10;
        armSum += d * d * d;
        temp /= 10;
    }
    info.isArmstrong = (original == armSum);
    
    return info;
}
```

### Sieve of Eratosthenes (Find all primes up to N)
```cpp
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return isPrime;
}
// Time: O(N log log N), Space: O(N)
```

### Prime Factorization
```cpp
vector<int> primeFactors(int n) {
    vector<int> factors;
    
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    
    if (n > 1) {
        factors.push_back(n);  // n itself is prime
    }
    
    return factors;
}
// Time: O(√N)
```

---

**Video Reference:** [Basic Math for DSA](https://youtu.be/1xNbjMdbjug?si=LiF-OvkGOSky9aTX)

**Created for DSA Revision** 📚

---

Happy Learning! 🚀

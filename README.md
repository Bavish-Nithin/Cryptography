#  Myszkowski Cipher

## Overview
The Myszkowski Cipher is a classical encryption technique that belongs to the family of transposition ciphers. Instead of changing the characters in the message, it rearranges their positions based on a given keyword.


---

## Key Concept
- A keyword is used to control the rearrangement of the plaintext.
- Each letter in the key is assigned a rank based on alphabetical order.
- Duplicate letters in the key receive the same rank.
- These duplicate-ranked columns are processed together during encryption.

---

##  Work Flow

### 1. Key Ranking
Each character in the key is assigned a rank.

Example:
Key: BALLOON  
Ranks: 2 1 3 3 4 4 5  

---

### 2. Matrix Formation
- The plaintext is written row-wise under the key.
- Each column corresponds to one character of the key.

---

### 3. Encryption Process
- Columns are read in ascending order of their ranks.
- If a rank appears only once:
  - The column is read from top to bottom.
- If a rank appears multiple times:
  - Those columns are read row by row together.

---

### 4. Decryption Process
- The ciphertext is placed back into the matrix using the same ranking rules.
- The plaintext is recovered by reading the matrix row-wise.

---

##  Program Workflow

1. Input plaintext and key  
2. Assign ranks to key characters  
3. Arrange plaintext into a matrix  
4. Encrypt using column-based reading rules  
5. Decrypt by reconstructing the matrix  
6. Retrieve original plaintext    

---

##  Limitations

- Not secure for modern cryptographic use  
- Vulnerable to pattern and frequency analysis  
- Mainly useful for learning and demonstration purposes  

---

##  Summary
The Myszkowski Cipher demonstrates how permutation-based encryption works by rearranging text using a structured key. It highlights how duplicate characters in a key can influence the encryption process.

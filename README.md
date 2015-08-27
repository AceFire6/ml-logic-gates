# Machine Learning Lab 2

## Instructions

1. `make run` to run the program
2. Follow the cli prompts
3. `make clean` to clean the directories

## Answers

1. You need 3 perceptrons. They need to be trained to do AND, OR, and NAND.
If we have inputs x0 and x1: x0, x1 go to both NAND and OR. The outputs from
NAND and OR are the inputs to AND.

2. Training Examples:

AND - 5 Iterations over the data set

| x0 | x1 | out |
|----|----|-----|
| 0  | 0  | 0   |
| 1  | 0  | 0   |
| 0  | 1  | 0   |
| 1  | 1  | 1   |

OR - 4 Iterations over the data set

| x0 | x1 | out |
|----|----|-----|
| 0  | 0  | 0   |
| 1  | 0  | 1   |
| 0  | 1  | 1   |
| 1  | 1  | 1   |

NAND - 12 Iterations over the data set

| x0 | x1 | out |
|----|----|-----|
| 0  | 0  | 1   |
| 1  | 0  | 1   |
| 0  | 1  | 1   |
| 1  | 1  | 0   |

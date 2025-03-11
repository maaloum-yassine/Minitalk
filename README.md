<h1 align="center">
	minitalk
</h1>

<p align="center">
  <img src="https://github.com/riceset/riceset/blob/main/42_badges/minitalke.png" alt="Push_swap 42 project badge"/>
</p>

## Description
**Minitalk** is a project from 42 School that involves creating a communication program using UNIX signals. The project consists of a **server** and a **client**, where the client sends a string message to the server using `SIGUSR1` and `SIGUSR2` signals.

## Features
- Communication between processes using UNIX signals
- Sends and receives strings using binary encoding
- Implements signal handling for reliability
- Works on UNIX-based systems (Linux/macOS)
- **Bonus:** Supports Unicode characters and multiple clients

## Usage
### Compilation
To compile the project, use the following command:
```sh
make
```
This will generate two executables:
- `server`
- `client`

For the **bonus**, compile with:
```sh
make bonus
```
This will generate:
- `server_bonus`
- `client_bonus`

### Running the Server
First, start the server by running:
```sh
./server
```
It will print a **Process ID (PID)**, which you need to send messages from the client.

### Sending a Message from the Client
Use the client to send a message to the server by specifying the **PID**:
```sh
./client <PID> "Hello, world!"
```
Replace `<PID>` with the actual server process ID.

For the **bonus**, use:
```sh
./client_bonus <PID> "Hello, Unicode! 😊"
```

## Implementation
- `server.c`: Handles incoming signals, reconstructs the message, and prints it.
- `client.c`: Sends the message character by character using signals.
- `server_bonus.c`: Supports multiple clients and Unicode characters.
- `client_bonus.c`: Sends Unicode messages efficiently.
- `minitalk.h`: Contains function prototypes and includes necessary headers.
- `Makefile`: Automates compilation and cleaning of binaries.

## UNIX Signals Used
Minitalk relies on the following UNIX signals:
- **SIGUSR1** (`kill -SIGUSR1 <PID>`) - Used to transmit a binary `0`
- **SIGUSR2** (`kill -SIGUSR2 <PID>`) - Used to transmit a binary `1`
- More about signals: [man 7 signal](https://man7.org/linux/man-pages/man7/signal.7.html)

## Restrictions
- Must use only `SIGUSR1` and `SIGUSR2` for communication.
- No use of external libraries (only standard system calls).
- Code must follow the 42 Norm.

## Possible Improvements
- Implement error handling for invalid PIDs.
- Optimize signal sending for performance.
- Support for larger messages or different data formats.


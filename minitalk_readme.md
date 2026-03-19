# Minitalk

## Description
Minitalk is a small project that allows sending strings from a client to a server using UNIX signals (`SIGUSR1` and `SIGUSR2`). The server receives messages and prints them character by character.

## Instructions

### 1. Compile

make

This will generate two executables `server` and `client`.

### 2. Run the server

./server

- The server will display its PID.  
- Keep the server running while sending messages.

### 3. Run the client

./client <server_pid> "<message>"

- Replace `<server_pid>` with the PID displayed by the server.  
- Replace `<message>` with the string you want to send.  
- Example:

./client 12345 "Hello World"

## Notes

- Only two signals are used: `SIGUSR1` (bit 0) and `SIGUSR2` (bit 1).  
- The client sends each character bit by bit.  
- \0 marks the end of the message.  
- Ensure messages with spaces are enclosed in quotes.

## Resourcers

- I used Ai to understand a fex things about bit translation.
- Oceano's youtube video https://www.youtube.com/watch?v=XqhY9WHahJQ
- Medium site https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24
- my mates
- 
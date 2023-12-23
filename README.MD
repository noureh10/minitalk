# Minitalk, a 42 project

![Minitalk](https://github.com/ayogun/42-project-badges/blob/main/covers/cover-minitalk-bonus.png?raw=true)

Minitalk is a C client-server application facilitating inter-process communication through UNIX signals. The communication mechanism involves the client transmitting data to the server using signals, specifically utilizing SIGUSR1 and SIGUSR2.

## Transmission Process

### Client-Side Transmission:

1. **Character to Binary Conversion:**
   The client converts ASCII-encoded characters into binary representation.

2. **Individual Bit Transmission:**
   Each bit of the binary representation is transmitted as a signal to the server using the kill() function.

3. **Signal Transmission Loop:**
   The client systematically sends signals for each bit, sequentially transmitting from MSB to LSB or vice versa.

### Server-Side Reception:

4. **Signal Handling:**
   The server has signal handlers for SIGUSR1 and SIGUSR2, interpreting signals received from the client.

5. **Bit Interpretation:**
   Upon signal reception, the server's handler determines whether it represents a 1 or 0 in the binary representation.

6. **Binary Reconstruction:**
   The server reconstructs the binary representation bit by bit, assembling the original data.

### Confirmation Mechanism:

#### Client-Side Confirmation:

- **SIGUSR1 (Acknowledgment):**
  - The client awaits an acknowledgment signal from the server after transmitting each bit.
  - Reception of SIGUSR1 indicates successful processing by the server.

- **SIGUSR2 (Retry Request):**
  - If acknowledgment is not received promptly, the client may send a retry request (SIGUSR2) to prompt the server to retransmit the last bit.

#### Server-Side Confirmation:

- **Acknowledgment Signal (SIGUSR1):**
  - The server responds to each successfully received bit with an acknowledgment signal (SIGUSR1), indicating readiness for the next bit.

- **Retry Handling (SIGUSR2):**
  - If the server encounters issues, it signals SIGUSR2, instructing the client to resend the previous bit for correction.

This compact architecture efficiently uses binary representation and UNIX signals for reliable data transmission between the client and server in the Minitalk application.

### Sources that helped me a lot in this project : 

Man pages : https://man7.org/linux/man-pages/man2/signal.2.html

Geeksforgeeks website : https://www.geeksforgeeks.org/signal-handling-in-linux-through-the-signal-function/ (lovely website)

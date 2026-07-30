# Task 4 – Network Programming and Inter-Process Communication

## Overview

This task demonstrates the fundamentals of network programming and communication between processes using Python. The objective was to understand how client and server applications communicate over a network using TCP sockets while applying basic security, validation, and error handling techniques. The implementation also demonstrates concurrent client handling through multithreading, allowing the server to communicate with multiple clients at the same time.

## Implementation

The project consists of two main programs: a TCP server and a TCP client. The server listens for incoming client connections on a specified IP address and port. When a client connects, the server creates a separate thread to handle that client independently. This allows multiple clients to communicate with the server simultaneously without interrupting each other.

A simple communication protocol was implemented for authentication and message exchange. Before sending messages, each client must provide a valid username and password. The server verifies the credentials before granting access. If authentication fails, the client connection is terminated.

After successful login, the client can send messages to the server. The server validates incoming data, rejects invalid or empty messages, and returns a confirmation response. The connection remains active until the client sends the EXIT command, after which the server closes the connection safely.

The implementation also includes exception handling to manage connection failures and unexpected errors. Proper connection management ensures that sockets are closed correctly when communication ends, preventing resource leaks.

## Testing

The server and client programs were executed on Ubuntu using separate terminal windows. The server was started first, followed by one or more client instances.

Authentication was tested using both valid and invalid usernames and passwords. Successful logins allowed message exchange, while incorrect credentials resulted in denied access.

Multiple clients were connected simultaneously to verify that the server could handle concurrent connections using threads. Various messages were exchanged to confirm successful communication, data validation, and proper connection management. Error handling was also tested by disconnecting clients and sending invalid input.

## Results

The implementation successfully established reliable communication between the client and server using TCP sockets. Authentication restricted access to authorised users, multithreading allowed multiple clients to communicate concurrently, and the server responded correctly to valid requests while handling invalid input appropriately. The error handling mechanisms maintained stable operation during testing.

## Conclusion

This task provided practical experience with network programming concepts used by operating systems and distributed applications. Implementing sockets, authentication, multithreading, data validation, and connection management improved understanding of reliable communication between processes across a network. The project demonstrated the importance of secure and efficient network services in modern operating systems.

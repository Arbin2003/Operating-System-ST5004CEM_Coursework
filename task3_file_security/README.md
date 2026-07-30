# Task 3 – File System Operations and Security

## Overview

This task focuses on implementing file system operations together with basic security features using Python. The objective was to understand how operating systems manage files while protecting them from unauthorized access. The project includes user authentication, file creation, reading, writing, deletion, file permission management, encryption and decryption, and audit logging. These features demonstrate the importance of security and access control in modern operating systems.

## Implementation

The project begins with a user authentication system. Before accessing the file management functions, users must enter a valid username and password. If the credentials are correct, access is granted; otherwise, the program denies access and terminates.

The file management module allows users to create new files, write data into files, read file contents, and delete files. Before performing operations, the program checks whether the requested file exists to prevent errors. Appropriate success or error messages are displayed after each operation.

File permission management is implemented using Python's operating system functions. Users can change a file to read-only mode or restore read and write permissions. This demonstrates how operating systems control access to files using permission settings.

To improve data security, the project includes file encryption and decryption using Base64 encoding. Although Base64 is primarily an encoding method rather than a secure encryption algorithm, it provides a simple demonstration of protecting file contents and restoring the original data when required.

An audit logging system records important user activities such as login attempts, file creation, reading, writing, deletion, permission changes, encryption, and decryption. Each log entry includes the date and time of the operation, allowing user actions to be monitored and reviewed.

## Testing

The system was tested by performing each file operation individually. User authentication was verified using both valid and invalid login credentials. File creation, writing, reading, and deletion were tested using different filenames to confirm correct behaviour.

Permission management was tested by changing files between read-only and read/write modes. Encryption and decryption were verified by comparing the original file contents before and after processing. Finally, the audit log was examined to ensure that every operation was recorded correctly with a timestamp.

## Results

The file management system successfully performed all required operations while applying basic security measures. Authentication prevented unauthorized access, permission management controlled file access, encryption and decryption modified file contents correctly, and the audit log maintained a complete record of user activities. All implemented features worked as expected during testing.

## Conclusion

This task provided practical experience with operating system file management and security concepts. Implementing authentication, permissions, encryption, and audit logging demonstrated how operating systems protect user data and monitor system activity. The project strengthened understanding of secure file handling and the importance of maintaining accurate records of user actions.

import socket
import threading

HOST = "127.0.0.1"
PORT = 5000

# Simple username/password database
USERS = {
    "Atom": "12345678",
    "Admin": "admin123"
}


def handle_client(client_socket, address):
    print(f"[NEW CONNECTION] {address} connected.")

    try:
        # Authentication
        login_data = client_socket.recv(1024).decode().strip()
        parts = login_data.split()

        if len(parts) != 3 or parts[0] != "LOGIN":
            client_socket.send("INVALID_LOGIN_FORMAT".encode())
            client_socket.close()
            return

        username = parts[1]
        password = parts[2]

        if username not in USERS or USERS[username] != password:
            client_socket.send("LOGIN_FAILED".encode())
            client_socket.close()
            print(f"[FAILED LOGIN] {address}")
            return

        client_socket.send("LOGIN_SUCCESS".encode())
        print(f"[LOGIN SUCCESS] {username} from {address}")

        while True:
            data = client_socket.recv(1024).decode()

            if not data:
                break

            data = data.strip()

            if data.upper() == "EXIT":
                client_socket.send("Goodbye!".encode())
                break

            if len(data) == 0:
                client_socket.send("ERROR: Empty message.".encode())
                continue

            print(f"[{username}] {data}")

            reply = f"RECEIVED: {data}"
            client_socket.send(reply.encode())

    except Exception as e:
        print("Error:", e)

    finally:
        client_socket.close()
        print(f"[DISCONNECTED] {address}")


def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server.bind((HOST, PORT))
    server.listen(5)

    print("=" * 50)
    print("TCP Server Started")
    print(f"Listening on {HOST}:{PORT}")
    print("Waiting for clients...")
    print("=" * 50)

    while True:
        client_socket, address = server.accept()

        thread = threading.Thread(
            target=handle_client,
            args=(client_socket, address)
        )

        thread.start()

        print(f"Active Connections: {threading.active_count() - 1}")


if __name__ == "__main__":
    main()

from multiprocessing import Process, Pipe


def sender(conn):
    message = "Hello from Process 1!"
    print("Process 1 sending:", message)
    conn.send(message)
    conn.close()


def receiver(conn):
    message = conn.recv()
    print("Process 2 received:", message)
    conn.close()


def main():
    parent_conn, child_conn = Pipe()

    p1 = Process(target=sender, args=(parent_conn,))
    p2 = Process(target=receiver, args=(child_conn,))

    p1.start()
    p2.start()

    p1.join()
    p2.join()

    print("\nIPC communication completed successfully.")


if __name__ == "__main__":
    main()

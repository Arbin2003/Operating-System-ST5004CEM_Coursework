from auth import login
from file_manager import (
    create_file,
    write_file,
    read_file,
    delete_file,
    make_read_only,
    make_read_write
)
from encryption import encrypt_file, decrypt_file
from logger import log_action


def menu():
    while True:
        print("\n========== Secure File Management ==========")
        print("1. Create File")
        print("2. Write File")
        print("3. Read File")
        print("4. Delete File")
        print("5. Make File Read Only")
        print("6. Make File Read/Write")
        print("7. Encrypt File")
        print("8. Decrypt File")
        print("9. Exit")

        choice = input("\nEnter your choice: ")

        if choice == "1":
            filename = input("Enter file name: ")
            create_file(filename)

        elif choice == "2":
            filename = input("Enter file name: ")
            write_file(filename)

        elif choice == "3":
            filename = input("Enter file name: ")
            read_file(filename)

        elif choice == "4":
            filename = input("Enter file name: ")
            delete_file(filename)

        elif choice == "5":
            filename = input("Enter file name: ")
            make_read_only(filename)

        elif choice == "6":
            filename = input("Enter file name: ")
            make_read_write(filename)

        elif choice == "7":
            filename = input("Enter file name: ")
            encrypt_file(filename)

        elif choice == "8":
            filename = input("Enter file name: ")
            decrypt_file(filename)

        elif choice == "9":
            log_action("User exited the program")
            print("\nThank you for using the Secure File Management System.")
            break

        else:
            print("Invalid choice. Please try again.")


def main():
    if login():
        log_action("User logged in successfully")
        menu()
    else:
        log_action("Failed login attempt")
        print("Access Denied")


if __name__ == "__main__":
    main()

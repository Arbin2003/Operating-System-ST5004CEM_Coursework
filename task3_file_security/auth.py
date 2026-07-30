USERS = {
    "Atom": "12345678"
}


USERS = {
    "Atom": "12345678"
}


def login():
    print("=" * 40)
    print(" Secure File Management System ")
    print("=" * 40)

    username = input("Username: ")
    password = input("Password: ")

    if username in USERS and USERS[username] == password:
        print("\nLogin successful!")
        print(f"Welcome, {username}!\n")
        return True

    else:
        print("\nInvalid username or password.")
        return False

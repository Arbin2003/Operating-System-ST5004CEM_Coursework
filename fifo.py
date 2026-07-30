def fifo(page_sequence, frame_size):
    frames = []
    page_hits = 0
    page_faults = 0

    print("\n----- FIFO Page Replacement -----")

    for page in page_sequence:

        if page in frames:
            page_hits += 1
            print(f"Page {page} -> HIT    Frames: {frames}")

        else:
            page_faults += 1

            if len(frames) < frame_size:
                frames.append(page)
            else:
                frames.pop(0)
                frames.append(page)

            print(f"Page {page} -> FAULT  Frames: {frames}")

    print("\nResults")
    print("Page Hits   :", page_hits)
    print("Page Faults :", page_faults)
    print("Hit Ratio   :", round(page_hits / len(page_sequence), 2))
    print("Fault Ratio :", round(page_faults / len(page_sequence), 2))

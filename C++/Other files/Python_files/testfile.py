import tkinter, keyboard, time
def update_label():
    clipboard_content = root.clipboard_get()
    label.config(text=clipboard_content)
    for line in clipboard_content.split("\n"):
        keyboard.write(line, delay=0)
        keyboard.press_and_release("enter")
        keyboard.press_and_release("home")
root = tkinter.Tk()
root.withdraw()
label = tkinter.Label(root, text="")
label.pack()
time.sleep(8)
update_label()
root.destroy()


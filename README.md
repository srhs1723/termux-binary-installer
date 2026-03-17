# 🐿️⚡ TMUXI - Termux Binary Installer

### Because typing `chmod +x` then `./` then `cp` is basically a war crime at this point.

---
```
<p align="center">
  <img src="https://img.shields.io/badge/written%20in-C-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/powered%20by-RAGE-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/works%20on-termux-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/bugs-yes-orange?style=for-the-badge" />
</p>
```
---

## 🤔 What is this?

You know that feeling when you download a binary in Termux and then you gotta do:

```bash
chmod +x coolscript
cp coolscript /data/data/com.termux/files/usr/bin/
And you're sitting there like a medieval scribe hand-copying manuscripts?

TMUXI fixes that.

Now you just do:

Bash

tmuxi -s coolscript
That's it. ONE command. We just saved you like 4 seconds of your life.
You're welcome. Go cure cancer with that extra time.

🚀 Installation
The ironic part (you gotta install the installer)
Bash

git clone https://github.com/yourusername/termux-bin-installer.git
cd termux-bin-installer
gcc tmuxi.c -o tmuxi
chmod +x tmuxi
cp tmuxi /data/data/com.termux/files/usr/bin/
Yes, you have to chmod and cp ONE MORE TIME to never do it again.
It's like paying for a gym membership to get in shape enough to cancel your gym membership.
The IRONY is not lost on me. I'm SWIMMING in it.

Or be fancy with Make (if you have it):
Bash

make
make install
📖 Usage
Bash

# Install a binary (the whole point of existence)
tmuxi -s myscript

# Install MULTIPLE binaries because you're a MANIAC
tmuxi -s script1 script2 script3

# Remove a binary (breakup arc)
tmuxi -r myscript

# List installed binaries (inventory check)
tmuxi -l

# Show version (existential validation)
tmuxi -v

# Show help (you're here aren't you)
tmuxi -h
🎭 Error Messages You Might See
Message	Translation
File not found. Did it ghost you?	The file doesn't exist. Check your spelling, Shakespeare.
Permission denied harder than a club bouncer	You don't have permission. Try crying.
Are you even running Termux??	The install directory doesn't exist. Sus.
Can't uninstall what doesn't exist. That's philosophy.	You tried to remove something that isn't there. Deep.
It's clinging on like a koala	File refused to be deleted. It's attached.
Your phone is COOKED	Memory allocation failed. Your phone needs therapy.
🧠 How it works
text

You: tmuxi -s myscript

tmuxi brain:
  1. Does this file exist? 🤔
     - No → roast the user
     - Yes → continue
  2. chmod +x that bad boy 🔓
  3. cp it to /data/data/com.termux/files/usr/bin/ 📦
  4. Confirm the installation with ✨ pizzazz ✨
  5. User types 'myscript' from anywhere
  6. World peace achieved 🌍
🤷 FAQ
Q: Why not just use a shell script?
A: Because C is FASTER and we are SPEED. Also I wanted to feel something
while writing code and suffering through pointer arithmetic made me feel ALIVE.

Q: Does this work outside Termux?
A: Technically yes if you change the install path. But this was BUILT for
Termux like pizza was built for 3 AM sadness.

Q: Is this production ready?
A: Is ANYTHING in your life production ready? Exactly. Ship it.

Q: Why is the binary called tmuxi?
A: TerMUX Installer. Also it sounds like a Pokémon and I respect that.

Q: I found a bug!
A: That's not a question. But also, it's a ✨feature✨. Open an issue and
I'll mass it in the next update between existential crises.

Q: Can I contribute?
A: YES. Please. I am ONE person running on coffee fumes and
unresolved childhood trauma. PRs are welcome like pizza at a party.

🗺️ Roadmap
 Basic install (-s)
 Basic remove (-r)
 List installed (-l)
 Batch install (multiple files)
 Error messages funnier than my life
 Auto-detect script type (shell, python, etc.)
 Backup before overwrite
 Config file for custom install paths
 World domination
 Fix that one bug I know exists but refuse to acknowledge
📜 License
text

MIT License

Copyright (c) 2024 

Permission is hereby granted to literally anyone to use this,
copy this, modify this, sell this (lol who would buy this), 
and do whatever you want with it.

Just don't blame me if it deletes your homework folder.
You didn't have homework in there anyway. We both know what was in there.
⭐ Star this repo
If this saved you even 0.3 seconds of your life, smash that star button
like it talked bad about your mom.

Every star gives a sleep-deprived developer the will to mass another commit
instead of staring at the ceiling questioning their career choices.

<p align="center"> <b>Made with 💀 and ☕ in Termux</b><br> <i>"I mass tools so I don't have to type two commands. I am the definition of productive laziness."</i> </p> ```

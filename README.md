![Logo](https://i.ibb.co/fVq2m2DT/Isekai-War-Banner.png)

# ✨ IsekaiWar!

✧ Freshman-year shoot 'em up, built in about 2 weeks ✧

❱ I made this project early in my freshman year at GamingCampus Lyon.                
The quality and architecture are quite terrible, as we had a tight deadline to build both the engine and the game.

It’s not reflective of my current skills, so please don’t judge too harshly :)
## 🌌 Features

#### ⚙️ Technical :
- Custom engine architecture based on SFML
- Ready for deployment (binaries available)
- Support for resource packs
#### 🕹 Gameplay :
- Simple menu with keybind settings
- Full gamepad support (menus included)
- Abilities and special bullets with effects
- Ultimate attacks with a "mana" system
- Multiple Power-Ups with different effects
- 5 different enemies with unique patterns
- 1 playable level (around 2 min of Gameplay)

↻ More features were planned, but we spent too much time on the engine.
## 📷 Screenshots

![Engine Startup](https://i.ibb.co/xqXfNgp6/Engine-Startup.png)

![Main Menu](https://i.ibb.co/XZRLWCPB/Main-Menu.png)

![Main Game](https://i.ibb.co/RkwDQdw5/Main-Game.png)
## 🧾 Lore

In IsekaiWar! the main protagonist Maxine (our teacher 😋) is 'teleported' by the main antagonist Truck-Kun 🚚💥 into a medieval fantasy world.

Maxine quickly discovers her destiny isn’t just to teach coding to dumb students.. But to wield it as a weapon 📐. Granted mysterious magical powers ✨ (and a questionable fireball spell she insists is "just science with flair" 🔥), Maxine forms a pact with a grumpy, ancient phoenix known only as The Fenix 🐦‍ who refuses to spell its name the normal way.

Together, they must defend the realm of Amstrad from bizarre, neon-lit spaceships 🚀🛸 pouring through tears in the sky, 🌌 invaders from an alternate universe where medieval tech was replaced by angry AI 🤖 and bad Wi-Fi 📶💢. These ships, known as the C64 Armada ⚔️, seek to flatten the land, pixel by pixel , and replace it with brainrot and overpriced NFTs 💸📉.

Now Maxine, armed with spells ✨, sarcasm, and the stubborn spirit of a data driven developer 📝, must blast through wave after wave of alien spaceships to uncover the truth: why Truck-Kun chose her, and what horrifying connection the invaders have with her own world’s school system 🏫⁉️
## 📥 Installation

### Precompiled Binaries
If you want to the game right away, precompiled binaries are available in the release section.

[Download Latest Release](https://github.com/SHARKgamestudio/IsekaiWar)


### Building From Source
First, clone the repository using your favorite Git client:
```bash
git clone https://github.com/SHARKgamestudio/IsekaiWar.git
```

This project uses a custom solution generator developed by my school teachers.        
To build the project, all you need to do is run the bash script at the following path:
```bash
./bin/make.bat
```

Finally, this project uses VCPKG in manifest mode to manage dependencies.        
If you are running Visual Studio, open your IDE and search for:        
```bash
Tools >> Command Line >> Developer PowerShell
```

Once opened, type the following command to install vcpkg for all versions of Visual Studio:
```bash
vcpkg integrate install
```

That’s it! You can now compile and run the project :)

⚠️ Side note: If you get errors about missing SFML DLLs, clean up the solution and build again.

## 💜 Credits

Thanks to [@gto634](https://github.com/gto634) for making this project with me :)

As well as a huge thanks to the SFML contributors and community :

[SFML Repository](https://github.com/SFML/SFML)

[SFML Website](https://www.sfml-dev.org/fr/)

![Logo](https://i.ibb.co/nMM9f8Td/MainMenu.png)

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
- Abilities and special bullets with effects
- Ultimate attacks with a "mana" system
- Multiple Power-Ups with different effects
- 5 different enemies with unique patterns
- 1 playable level (around 2 min of Gameplay)
  
↻ More features were planned, but we spent too much time on the engine.

## 📥 Installation

### Precompiled Binaries
If you want the game right away, precompiled binaries are available in the release section.

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
## 💜 Credits

Thanks to [@gto634](https://github.com/gto634) for making this project with me :)

As well as a huge thanks to the SFML contributors and community :

[SFML Repository](https://github.com/SFML/SFML)

[SFML Website](https://www.sfml-dev.org/fr/)

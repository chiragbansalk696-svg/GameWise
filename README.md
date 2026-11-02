# GameWise
GameWise is a Gaming Budgeting Command Line Programme , helping you to make budget goals , make your games collection and get XP points ,make wishlist etc


# 🎮 GameWise – Your Personal Gaming Companion

**Discover Games. Manage Your Collection. Save Smart. Level Up!**

GameWise is a menu-driven command-line application developed using the C programming language. It helps gamers discover games, manage their gaming collections, organise wishlists, track savings goals, and earn XP through a simple reward system.

The project combines gaming discovery with financial planning to encourage smarter gaming purchases.

---

## ✨ Features

### 1. 🎯 Game Catalogue
- Explore a predefined catalogue of 20 video games.
- View game names, genres, platforms, and sample prices.
- Browse different gaming categories.

### 2. 🧠 Game Recommendations
- Get recommendations based on preferred genre.
- Filter games according to platform.
- Set a maximum budget.
- View a simple match score for recommended games.

### 3. ❤️ Wishlist Management
- Add games you want to purchase.
- View your wishlist.
- Prevent duplicate entries.

### 4. 🎮 Personal Game Collection
- Add games you already own.
- View your gaming collection.
- Earn XP for adding games.

### 5. 💰 Gaming Savings Tracker
- Create individual savings goals for games.
- Enter your existing savings.
- Add additional contributions whenever you save money.
- Automatically calculate remaining amounts and savings progress.
- Manage multiple savings goals simultaneously.

### 6. 🏆 XP and Level System
Earn XP through activities and savings milestones.

| Activity | XP |
|---|---:|
| Create a savings goal | +10 |
| Add a game to collection | +5 |
| Reach 25% savings | +25 |
| Reach 50% savings | +50 |
| Reach 75% savings | +75 |
| Complete a savings goal | +150 |

**Player Levels:**

| Level | Rank | XP Required |
|---|---|---:|
| 1 | Beginner | 0–99 |
| 2 | Game Explorer | 100–249 |
| 3 | Pro Saver | 250–499 |
| 4 | Gaming Strategist | 500–999 |
| 5 | Legendary Gamer | 1000+ |

### 7. 📊 Dashboard
- View total accumulated XP.
- Check current player level.
- Monitor savings progress.
- View wishlist and collection counts.
- Track total money allocated towards savings goals.

### 8. 💾 Persistent Data Storage
- Saves user progress using binary file handling.
- Retains wishlist, collection, savings goals, and XP.
- Loads previously saved data when the application starts.
- Allows users to continue their savings journey after restarting the application.

---

## 📸 Screenshots

Screenshots of the application running in the terminal.

### 1. Main Menu
<img width="660" height="444" alt="Screenshot (307)" src="https://github.com/user-attachments/assets/37f25900-7695-4eb8-92ee-86bd9948a2cb" />


### 2. Game Catalogue
<img width="680" height="653" alt="Screenshot (308)" src="https://github.com/user-attachments/assets/9439b515-7f77-4687-bf6f-163f28d9995d" />


### 3. Game Recommendations
<img width="574" height="414" alt="Screenshot (309)" src="https://github.com/user-attachments/assets/f0275df0-6975-4493-8621-4fc83c71a5c1" />


### 4. Wishlist
<img width="515" height="699" alt="Screenshot (310)" src="https://github.com/user-attachments/assets/998853cb-fef1-4a50-8898-c110c11bcecf" />
<img width="548" height="163" alt="Screenshot (311)" src="https://github.com/user-attachments/assets/4950ad5f-d932-4788-97da-edf8092456c8" />


### 5. Personal Game Collection
<img width="521" height="816" alt="Screenshot (314)" src="https://github.com/user-attachments/assets/fd0c6893-ec8b-4ba1-ad4e-4a243cef81af" />


### 6. Savings Goal Creation
<img width="634" height="796" alt="Screenshot (312)" src="https://github.com/user-attachments/assets/bf513b3f-c2a9-461a-82be-70331cb85777" />
<img width="676" height="251" alt="Screenshot (316)" src="https://github.com/user-attachments/assets/2defe641-39ce-4083-beda-daded420bae3" />


### 7. Savings Progress
<img width="563" height="266" alt="Screenshot (313)" src="https://github.com/user-attachments/assets/14792578-939c-4a35-9ccb-2a7d9e1cb692" />


### 8. XP and Dashboard
<img width="646" height="453" alt="Screenshot (317)" src="https://github.com/user-attachments/assets/cdaa4586-d154-49af-a921-593c5be2466c" />


### 9. Persistent Data Storage
<img width="533" height="508" alt="Screenshot (318)" src="https://github.com/user-attachments/assets/78dc18bd-68fc-4333-bd6c-ae61932449c2" />


---

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **IDE:** Visual Studio Code
- **Storage:** Binary file handling
- **Libraries:** `stdio.h`, `string.h`

---

## 📚 C Programming Concepts Demonstrated

- Variables and data types
- Input and output operations
- Operators and expressions
- Conditional statements (`if-else`)
- Switch-case
- Loops (`for`, `do-while`)
- One-dimensional and two-dimensional arrays
- Strings and string handling
- File handling (`fopen`, `fread`, `fwrite`, `fclose`)

---

## 🚀 Getting Started

### Prerequisites

Make sure you have:
- GCC compiler installed.
- Visual Studio Code or any C-compatible IDE.
- A terminal or command prompt.

### Installation

**1. Clone the repository**

```bash
git clone https://github.com/YOUR-USERNAME/GameWise.git
```

**2. Navigate to the project directory**

```bash
cd GameWise
```

**3. Compile the program**

```bash
gcc gamewise.c -o gamewise.exe
```

**4. Run the application**

On Windows:

```bash
.\gamewise.exe
```

On Linux:

```bash
./gamewise
```

---

## 💾 Data Storage

GameWise uses a binary file named `gamewise.dat` to store user information.

The file is automatically created when the application saves its data.

It stores:
- Wishlist entries
- Owned games
- Savings goals
- Savings contributions
- XP and milestone progress

**Important:** Keep `gamewise.dat` in the application's working directory to retain your progress. Deleting it will remove the saved user data.

---

## ⚠️ Current Limitations

- The game catalogue contains 20 predefined games.
- Game prices are illustrative sample values and are not live store prices.
- All currently listed games use PC as their platform.
- Recommendations are based on predefined rules and filters, not an AI model.
- The application supports a maximum of 10 simultaneous savings goals.
- The application is currently terminal-based and does not have a graphical user interface.
- Save data is intended for use with the same program and compatible environment.

---

## 🔮 Future Enhancements

- Integration with gaming databases and APIs such as RAWG or IGDB.
- Live game prices and discount tracking.
- Support for multiple gaming platforms.
- Advanced recommendation algorithms.
- Graphical user interface.
- Game playtime and achievement tracking.
- More detailed gaming statistics.
- Exportable gaming and savings reports.

---

## 🎯 Project Objective

The primary objective of GameWise is to combine gaming discovery, personal library management, and savings tracking into one application while demonstrating the practical use of C programming concepts.

It aims to encourage gamers to make informed purchasing decisions while making the overall gaming experience more organised and engaging.

---

## 👨‍💻 Developer

**Developed as an LTPS (Learning Through Problem Solving) project using C programming.**

---

⭐ If you find this project interesting, consider giving the repository a star!

**GameWise – Discover Games. Save Smart. Level Up!**

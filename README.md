Liar’s Dice (C++ / Visual Studio)
   
A console implementation of Liar’s Dice, focused on clean object-oriented design and a testable game loop. Built in modern C++ with a Visual Studio solution for quick setup.
Who this is for: Reviewers of my internship portfolio and peers interested in object-oriented game architecture in C++.
________________________________________
Table of Contents <br>
•	Overview
•	Game Rules (Brief)
•	Architecture
•	Key Classes
•	Getting Started
•	How to Play (Usage)
•	Design Notes
•	Testing Tips
•	Future Improvements
•	Acknowledgments
•	About the Developer
•	License
________________________________________
Overview
This project implements the core mechanics of Liar’s Dice in C++. The goal was to practice: - Object-oriented modeling (players, dice, and a game loop) - State management across rounds and bids - Clear separation of concerns between I/O and game logic
The repository includes a Visual Studio solution for straightforward builds on Windows.
________________________________________
Game Rules (Brief)
•	Each player starts with a set of dice (commonly five).

•	Players take turns bidding on the total count of a face value among all dice in play (e.g., “there are at least eight 3s”).

•	The next player must either raise the bid (increase quantity or face, per your table rules) or call (challenge the previous bid).

•	On a call, all dice are revealed; if the bid was invalid, the bidder loses a die; if valid, the caller loses a die.

•	Play continues until one player remains with the dice.
________________________________________
Architecture
High-level structure:
src/
  Liar'sDice.cpp        // Program entry; wiring + startup
  LDGameLoop.h/.cpp     // Turn progression, bidding flow, round resolution
  Player.h/.cpp         // Player state: dice, active status, decisions
  Dice.h                // Dice representation / rollsproject/
  Rebecca.SC.Liar'sDice.sln, .vcxproj* // Visual Studio solution & project files
________________________________________
Key Classes
•	Dice (Dice.h): Encapsulates per-die behavior (values/rolls).
•	Player (Player.h/.cpp): Tracks each player’s dice and status; surface for input/AI.
•	LDGameLoop (LDGameLoop.h/.cpp): Orchestrates turns, validates bids, resolves calls, and manages round/termination logic.
•	main (Liar'sDice.cpp): Entry point; configures the game and delegates to LDGameLoop.
________________________________________
Getting Started
Prerequisites
•	Windows with Visual Studio (any recent Community/Professional edition with C++ workload).
  Build & Run
1.	Clone this repository.
2.	Open the solution:
  Rebecca.SC.Liar'sDice.sln in Visual Studio.
3.	Set configuration to Debug or Release.
4.	Build the solution and Run (Ctrl+F5).
________________________________________
How to Play (Usage)
1.	Launch the program.
2.	Choose the number of players (and any prompted options).
3.	On your turn:
  Raise the current bid (increase quantity and/or face per the rules),
  or Call to challenge the previous bid.
4.	The game loop reveals dice on a call, updates dice counts, and proceeds until one player remains.
________________________________________
Design Notes
•	Separation of Concerns:
The game flow is in LDGameLoop, while Player and Dice remain focused on state and behavior.
•	Testability:
By isolating core logic from console I/O, the engine can be adapted to a GUI/Web front-end later.
•	Extensibility:
Rules variants (e.g., wild ones, exact calls, different dice counts) can be toggled in the loop or via config.
________________________________________
Testing Tips
•	Deterministic seeds: Add a seed parameter for dice rolls to create reproducible scenarios during testing.
•	Scripted rounds: Stub player input to auto-play sequences that hit edge cases (e.g., rapid calls, high bids).
•	Boundary checks: Verify transitions when players lose their last die and when only two players remain.
________________________________________
Future Improvements
•	Stronger input validation and clearer prompts for invalid bids.
•	Configurable rulesets (wildface on/off, minimum raise constraints, exact-call mechanics).
•	Basic AI opponents with heuristic bidding (portfolio-friendly: shows algorithmic thinking).
•	Unit tests for bid validation and round resolution (GoogleTest/Catch2).
•	Cross-platform build via CMake to supplement the Visual Studio solution.
•	Refactors to reduce any console I/O in core logic for easier reuse.
________________________________________
Acknowledgments
•	Classic Liar’s Dice rules as commonly played in tabletop settings.
•	Built as a learning project to demonstrate C++ OOP, game loop design, and iterative improvement.
________________________________________
About the Developer
Rebecca St. Clair
🎓 Computer Science Student | Aspiring Software Engineer | Writer
Passionate about combining creativity and logic—whether through elegant C++ design or imaginative storytelling. This project reflects an ongoing focus on object-oriented architecture, maintainable systems, and practical application of core CS principles.
Portfolio
LinkedIn
________________________________________
License
MIT License. See the LICENSE file for details.

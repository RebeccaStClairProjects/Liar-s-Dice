<h1 style="text-align:center; font-size:2.5em;">Liar’s Dice (C++ / Visual Studio)</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue.svg" alt="C++17 Badge"/>
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-purple.svg" alt="Visual Studio Badge"/>
  <img src="https://img.shields.io/badge/Status-Complete-brightgreen.svg" alt="Project Status Badge"/>
  <img src="https://img.shields.io/badge/License-MIT-lightgrey.svg" alt="License Badge"/>
</p>

<p style="font-size:1.1em;">A console implementation of <b>Liar’s Dice</b>, focused on clean object-oriented design and a testable game loop. Built in modern C++ with a Visual Studio solution for quick setup.</p>

<blockquote><b>Who this is for:</b> Reviewers of my internship portfolio and peers interested in object-oriented game architecture in C++.</blockquote>

<hr>

<h2>Table of Contents</h2>
<ul>
<li><a href="#overview">Overview</a></li>
<li><a href="#game-rules">Game Rules (Brief)</a></li>
<li><a href="#architecture">Architecture</a></li>
<li><a href="#key-classes">Key Classes</a></li>
<li><a href="#getting-started">Getting Started</a></li>
<li><a href="#how-to-play">How to Play (Usage)</a></li>
<li><a href="#design-notes">Design Notes</a></li>
<li><a href="#testing-tips">Testing Tips</a></li>
<li><a href="#future-improvements">Future Improvements</a></li>
<li><a href="#acknowledgments">Acknowledgments</a></li>
<li><a href="#about-developer">About the Developer</a></li>
<li><a href="#license">License</a></li>
</ul>

<hr>

<h2 id="overview">Overview</h2>
<p>This project implements the core mechanics of <b>Liar’s Dice</b> in C++. The goal was to practice:</p>
<ul>
<li><b>Object-oriented modeling</b> (players, dice, and a game loop)</li>
<li><b>State management</b> across rounds and bids</li>
<li><b>Clear separation of concerns</b> between I/O and game logic</li>
</ul>
<p>The repository includes a Visual Studio solution for straightforward builds on Windows.</p>

<hr>

<h2 id="game-rules">Game Rules (Brief)</h2>
<ul>
<li>Each player starts with a set of dice (commonly five).</li>
<li>Players take turns <b>bidding</b> on the total count of a face value among <i>all dice in play</i> (e.g., “there are at least eight 3s”).</li>
<li>The next player must either <b>raise the bid</b> (increase quantity or face) or <b>call</b> (challenge the previous bid).</li>
<li>On a call, all dice are revealed; if the bid was invalid, the bidder loses a die; if valid, the caller loses a die.</li>
<li>Play continues until one player remains with dice.</li>
</ul>

<hr>

<h2 id="architecture">Architecture</h2>
<pre>
src/
  Liar'sDice.cpp        // Program entry; wiring + startup
  LDGameLoop.h/.cpp     // Turn progression, bidding flow, round resolution
  Player.h/.cpp         // Player state: dice, active status, decisions
  Dice.h                // Dice representation / rolls
project/
  Rebecca.SC.Liar'sDice.sln, .vcxproj* // Visual Studio solution & project files
</pre>

<hr>

<h2 id="key-classes">Key Classes</h2>
<ul>
<li><b>Dice</b> (<code>Dice.h</code>): Encapsulates per-die behavior (values/rolls).</li>
<li><b>Player</b> (<code>Player.h/.cpp</code>): Tracks each player’s dice and status; surface for input/AI.</li>
<li><b>LDGameLoop</b> (<code>LDGameLoop.h/.cpp</code>): Orchestrates turns, validates bids, resolves calls, and manages round/termination logic.</li>
<li><b>main</b> (<code>Liar'sDice.cpp</code>): Entry point; configures the game and delegates to <code>LDGameLoop</code>.</li>
</ul>

<hr>

<h2 id="getting-started">Getting Started</h2>
<h3>Prerequisites</h3>
<ul>
<li><b>Windows</b> with <b>Visual Studio</b> (any recent Community/Professional edition with C++ workload).</li>
</ul>

<h3>Build & Run</h3>
<ol>
<li><b>Clone</b> this repository.</li>
<li>Open the solution: <code>Rebecca.SC.Liar'sDice.sln</code> in Visual Studio.</li>
<li>Set configuration to <b>Debug</b> or <b>Release</b>.</li>
<li><b>Build</b> the solution and <b>Run</b> (Ctrl+F5).</li>
</ol>

<hr>

<h2 id="how-to-play">How to Play (Usage)</h2>
<ol>
<li>Launch the program.</li>
<li>Choose the number of players (and any prompted options).</li>
<li>On your turn:
  <ul>
    <li><b>Raise</b> the current bid (increase quantity and/or face per the rules), or</li>
    <li><b>Call</b> to challenge the previous bid.</li>
  </ul>
</li>
<li>The game loop reveals dice on a call, updates dice counts, and proceeds until one player remains.</li>
</ol>

<hr>

<h2 id="design-notes">Design Notes</h2>
<ul>
<li><b>Separation of Concerns:</b> The game flow is in <code>LDGameLoop</code>, while <code>Player</code> and <code>Dice</code> remain focused on state and behavior.</li>
<li><b>Testability:</b> By isolating core logic from console I/O, the engine can be adapted to a GUI/Web front-end later.</li>
<li><b>Extensibility:</b> Rules variants (wild ones, exact calls, different dice counts) can be toggled in the loop or via config.</li>
</ul>

<hr>

<h2 id="testing-tips">Testing Tips</h2>
<ul>
<li><b>Deterministic seeds:</b> Add a seed parameter for dice rolls to create reproducible scenarios during testing.</li>
<li><b>Scripted rounds:</b> Stub player input to auto-play sequences that hit edge cases (e.g., rapid calls, high bids).</li>
<li><b>Boundary checks:</b> Verify transitions when players lose their last die and when only two players remain.</li>
</ul>

<hr>

<h2 id="future-improvements">Future Improvements</h2>
<ul>
<li><b>Stronger input validation</b> and clearer prompts for invalid bids.</li>
<li><b>Configurable rulesets</b> (wildface on/off, minimum raise constraints, exact-call mechanics).</li>
<li><b>Basic AI opponents</b> with heuristic bidding (portfolio-friendly: shows algorithmic thinking).</li>
<li><b>Unit tests</b> for bid validation and round resolution (GoogleTest/Catch2).</li>
<li><b>Cross-platform build</b> via CMake to supplement the Visual Studio solution.</li>
<li><b>Refactors</b> to reduce console I/O in core logic for easier reuse.</li>
</ul>

<hr>

<h2 id="acknowledgments">Acknowledgments</h2>
<ul>
<li>Classic <b>Liar’s Dice</b> rules as commonly played in tabletop settings.</li>
<li>Built as a learning project to demonstrate C++ OOP, game loop design, and iterative improvement.</li>
</ul>

<hr>

<h2 id="about-developer">About the Developer</h2>
<p><b>Rebecca St. Clair</b><br>
🎓 <i>Computer Science Student | Aspiring Software Engineer | Writer</i><br>
Passionate about combining creativity and logic—whether through elegant C++ design or imaginative storytelling. This project reflects an ongoing focus on object-oriented architecture, maintainable systems, and practical application of core CS principles.</p>

<p>
<a href="https://github.com/RebeccaStClairProjects"><img src="https://img.shields.io/badge/Portfolio-RebeccaStClairProjects-blue" alt="Portfolio Badge"></a><br>
<a href="https://www.linkedin.com/in/rebecca-stclair/"><img src="https://img.shields.io/badge/LinkedIn-RebeccaStClair-blue?logo=linkedin" alt="LinkedIn Badge"></a>
</p>

<hr>

<h2 id="license">License</h2>
<p>MIT License. See the <code>LICENSE</code> file for details.</p>

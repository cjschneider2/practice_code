__elixir-pdx/pang__

---
#Overview

The goal here is to simulate an N-way game of ping pong.

The rules are as follows:

1. Each game must have 2 or more players before starting.
2. When a player enters a game they serve their own ball to a random opponent.
3. When an opponent hits a ball to a player, the player has a 33% chance of missing.
   1. If they miss, then they notify the ball's owner, and the opponent who hit it to them scores a point, and the owner again serves their ball into play.
   2. If they hit, then the ball hurls at lightspeed into the unsuspecting court of another random player.
4. The first player to 11 points wins a match.
5. The first player to win 5 maches wins the game.


**Prerequisites:**
* [elixir](http://elixir-lang.org/install.html)

---

#Getting Started

###Clone this repository.
	
	$ cd ~/Repositories
	$ git clone https://github.com/elixir-pdx/pang.git
	$ cd pang

#Hacking

You may find it helpful to play with your code in Elixir's `iex` interactive console. If you want to do that and autoload the console session with your code then you can do the following from the project root:

	$ iex -S mix

That will make sure that you're running `iex` inside your project's build environment.

#Building

To compile your project simply run this from the project root:

	$ mix compile

#Testing

To run the test suite defined in `test/pang.exs` then run this from the project root:

	$ mix test

__elixir-pdx/best_actor__

---
#Overview

This exercise is designed to be an introduction to both Elixir and the basics of its concurrency model.

The challenge is to implement the following story.  Three or more Actors are going to be asked to vote preferentially who they
consider to be both the best actor and the runner-up amongst all the available Actors.  So 1st and 2nd place.  Then the votes will be tallied, making sure to consider __all__ the ballots, and the winner for runner-up and then best actor will be presented by the host.

**Prerequisites:**
* [elixir](http://elixir-lang.org/install.html)

---

#Getting Started

###Clone this repository.
  
    $ cd ~/Repositories
    $ git clone https://github.com/elixir-pdx/best_actor.git
    $ cd best_actor

#Hacking

You may find it helpful to play with your code in Elixir's `iex` interactive console. If you want to do that and autoload the console session with your code then you can do the following from the project root:

    $ iex -S mix

That will make sure that you're running `iex` inside your project's build environment.

#Building

To compile your project simply run this from the project root:

    $ mix compile

#Testing

To run the test suite defined in `test/best_actor_test.exs` then run this from the project root:

    $ mix test

defmodule Host do
  def greet do
    receive do
      {:choke, msg} ->
        IO.puts("Derp! Derp! #{msg} I'm dying up here!")
      {:shine, msg} ->
        IO.puts("Good evening folks and welcome to the #{msg}")
        greet()
    end
  end
end

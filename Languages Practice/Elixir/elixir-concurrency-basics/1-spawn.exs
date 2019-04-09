defmodule Greeter do
  def greet(name) do
    IO.puts "Hello, #{name}!"
  end
end

# Greeter.greet("Elixir Louisville")

# pid = spawn(Greeter, :greet, ["Elixir Louisville"])
# Process.alive?(pid)

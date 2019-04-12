defmodule Greeter do
  def greet do
    receive do
      {sender, name} ->
        send sender, {:ok, "Hello, #{name}!"}
    end
  end
end

# Greeter.greet

# pid = spawn(Greeter, :greet, [])
# send(pid, {self, "Elixir Louisville"})
# receive do
#   {:ok, message} ->
#     IO.puts(message)
# end

# pid = spawn(Greeter, :greet, [])
# send(pid, {self, "Elixir Louisville"})
# flush

# pid = spawn(Greeter, :greet, [])
# Process.alive?(pid)
# send(pid, {self, "Elixir Louisville"})
# Process.alive?(pid)

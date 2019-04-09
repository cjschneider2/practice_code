defmodule Liveportal.Door do
  def start_link(name) do
    Agent.start_link(fn -> [] end, name: name)
  end

  def push(name, []), do: :ok
  def push(name, [ head | tail ]) do
    Agent.get_and_update(name, fn state -> {:ok, [head | state]} end)
    push(name, tail)
  end
  def push(name, item), do: push(name, [item])

  def pop(name) do
    Agent.get_and_update(name, fn
      [] -> {[], []}
      [ head | tail ] -> {head, tail}
    end)
  end
end

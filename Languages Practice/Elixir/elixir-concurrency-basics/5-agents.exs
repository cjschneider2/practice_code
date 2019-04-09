defmodule CounterAgent do
  def start_link do
    {:ok, pid} = Agent.start_link(fn -> 0 end)
    pid
  end

  def get(pid) do
    Agent.get(pid, fn state -> state end)
  end

  def inc(pid, n \\ 1) do
    Agent.get_and_update(pid, fn state -> {state + n, state + n} end)
  end

  def dec(pid, n \\ 1) do
    Agent.get_and_update(pid, fn state -> {state - n, state - n} end)
  end
end

# pid = CounterAgent.start_link
# CounterAgent.get(pid)
# CounterAgent.inc(pid)
# CounterAgent.inc(pid, 10)
# CounterAgent.dec(pid, 1)

defmodule Counter do
  def count(n) do
    receive do
      {:inc, sender} ->
        n = n + 1
        send sender, {:ok, n}
        count(n)
      {:dec, sender} ->
        n = n - 1
        send sender, {:ok, n}
        count(n)
    end
  end
end

# pid = spawn(Counter, :count, [0])
# send(pid, {:inc, self})
# flush
# send(pid, {:inc, self})
# flush
# send(pid, {:dec, self})
# flush

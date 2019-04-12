# run with `elixir 4-process-death.exs`

defmodule Broken do
  def explode do
    :timer.sleep(500)
    exit(:exploded)
  end
end

# spawn(Broken, :explode, [])
# receive do
#   msg ->
#     IO.puts "RECEIVED: #{inspect msg}"
#   after 1000 ->
#     IO.puts "TIMEOUT"
# end

# spawn_link(Broken, :explode, [])
# receive do
#   msg ->
#     IO.puts "RECEIVED: #{inspect msg}"
#   after 1000 ->
#     IO.puts "TIMEOUT"
# end

spawn_monitor(Broken, :explode, [])
receive do
  msg ->
    IO.puts "RECEIVED: #{inspect msg}"
  after 1000 ->
    IO.puts "TIMEOUT"
end

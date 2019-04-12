# The code we wish we had
# See: https://www.howistart.org/posts/elixir/1

# Shoot two doors: one orange, another blue
iex(1)> Portal.shoot(:orange)
{:ok, #PID<0.72.0>}
iex(2)> Portal.shoot(:blue)
{:ok, #PID<0.74.0>}

# Start transferring the list [1, 2, 3, 4] from orange to blue
iex(3)> portal = Portal.transfer(:orange, :blue, [1, 2, 3, 4])
#Portal<
       :orange <=> :blue
  [1, 2, 3, 4] <=> []
>

# Now every time we call push_right, data goes to blue
iex(4)> Portal.push_right(portal)
#Portal<
    :orange <=> :blue
  [1, 2, 3] <=> [4]
>

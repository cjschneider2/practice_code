defmodule Liveportal do
  use Application
  require Logger

  # See http://elixir-lang.org/docs/stable/elixir/Application.html
  # for more information on OTP Applications
  def start(_type, _args) do
    import Supervisor.Spec, warn: false

    children = [
      # Define workers and child supervisors to be supervised
      worker(Liveportal.Door, []),
    ]

    # See http://elixir-lang.org/docs/stable/elixir/Supervisor.html
    # for other strategies and supported options
    opts = [strategy: :simple_one_for_one, name: Liveportal.Supervisor]
    Supervisor.start_link(children, opts)
  end

  def shoot(name) do
    Supervisor.start_child(Liveportal.Supervisor, [ name ])
  end

  def transfer(left, right, garbage) do
    Liveportal.Door.push(left, garbage)
    {left, right}
  end

  def push_right(portal = {left, right}) do
    trash = Liveportal.Door.pop(left)
    Logger.info("moving #{trash} from #{inspect left} to #{inspect right}")
    Liveportal.Door.push(right, trash)
    portal
  end
end

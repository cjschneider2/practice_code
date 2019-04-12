defmodule Show do
  def begin do
    jimmy = spawn(Host, :greet, [])
    send jimmy, {:choke, "2nd Elixir Games PDX Awards!"}
  end
end

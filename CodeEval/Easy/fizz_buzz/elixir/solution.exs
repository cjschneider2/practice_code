# Our modules & functions

defmodule Foo do

  def solution(:ok, file) do
    # read the lines and inflict our function upon the input >:P
    case IO.read(file, :line) do
      str when is_binary(str) ->
        [a, b, c] = String.split(str)
        {x,_} = Integer.parse(a)
        {y,_} = Integer.parse(b)
        {n,_} = Integer.parse(c)
        fb(x,y,n)
        solution(:ok, file)
      _ -> solution(:fail, file)
    end
  end

  def solution(:fail, file) do
    File.close(file)
  end

  def fb(x, y, n) do
    fb(x, y, n, [], 1)
  end

  def fb(x, y, n, acc, itr) when itr <= n do
    i = cond do
      rem(itr, x) == 0 and rem(itr,y) == 0 -> "FB"
      rem(itr, x) == 0 -> "F"
      rem(itr, y) == 0 -> "B"
      true -> " "
    end
    fb(x,y,n,[acc|i],itr+1)
  end

  def fb(_x, _y, _n, acc, _itr) do
    IO.puts(acc)
  end

end

## This is the start of the solution script
# open the file
{:ok, file} = File.open "input.txt"
Foo.solution(:ok, file)

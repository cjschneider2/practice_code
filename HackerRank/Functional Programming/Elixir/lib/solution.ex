defmodule Solution do

  def array_of_n_elements() do
    s = String.split(IO.read(:stdio, :line), [" ", "\n"])
    {k, _} = Integer.parse(List.first(s))
    0..(k - 1)
    |> Enum.map(fn x -> x end)
    |> IO.inspect(limit: :infinity)
  end

  def reverse_a_list() do
    IO.read(:stdio, :all)
    |> String.split([" ", "\n"])
    |> Enum.map(fn x -> String.to_integer(x) end)
    |> List.foldr([], fn f, _acc -> IO.inspect(f) end)
  end

  def sum_of_odd_elements() do
    IO.read(:stdio, :all)
    |> String.split([" ", "\n"])
    |> Enum.map(fn x -> String.to_integer(x) end)
    |> Enum.filter(fn x -> Integer.mod(x, 2) == 1 end)
    |> Enum.sum
    |> IO.inspect()
  end

  def list_length() do
    IO.read(:stdio, :all)
    |> String.split([" ", "\n"])
    |> Enum.count(fn _x -> true end)
    |> IO.inspect()
  end

  def update_list() do
    IO.read(:stdio, :all)
    |> String.split([" ", "\n"])
    |> Enum.map(
         fn x -> String.to_integer(x)
                 |> abs()
                 |> IO.inspect()
         end
       )
  end

  def evaluating_e_x() do
    count = IO.read(:stdio, :line)
            |> String.split([" ", "\n"])
            |> List.first
            |> String.to_integer

    input = IO.read(:stdio, :all)
            |> String.split([" ", "\n"])
            |> Enum.take(count)
            |> Enum.map(fn x -> String.to_float(x) end)

    input
    |> Enum.map(
         fn x -> e_x(x)
                 |> Float.round(4)
                 |> IO.inspect
         end
       )
  end

  def sums_of_power() do
    sum = read_line_as_integer();
    power = read_line_as_integer();
    IO.inspect(number_of_ways(sum, power, 1))
  end

  def number_of_ways(x, n, c) do
    val = x - pow(c, n)
    case val do
      0 -> 1
      _ when val < 0 -> 0
      _ -> Enum.sum(
             [
               number_of_ways(val, n, c + 1),
               number_of_ways(x, n, c + 1)
             ]
           )
    end
  end

  def read_line_as_integer() do
    IO.read(:stdio, :line)
    |> String.split([" ", "\n"])
    |> List.first
    |> String.to_integer
  end

  def e_x(x) do
    0..9
    |> Enum.map(fn i -> pow(x, i) / fact(i) end)
    |> IO.inspect
    |> Enum.sum
  end

  def fact(0), do: 1
  def fact(x) when x > 0, do: x * fact(x - 1)

  def pow(n, k), do: pow(n, k, 1)
  def pow(_, 0, acc), do: acc
  def pow(n, k, acc), do: pow(n, k - 1, n * acc)

end

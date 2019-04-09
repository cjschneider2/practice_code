defmodule HR do
  def parse_time(in_time) do
    [hh_s, mm_s, ss_s, apm] = Regex.run(~r/(\d?\d):(\d\d):(\d\d)(AM|PM)/, in_time, capture: :all_but_first)
    hh = hh_s |> Integer.parse |> elem(0)
    ap = case {apm, hh} do
           {"AM", 12} -> -12
           {"AM", _ } -> 0
           {"PM", 12} -> 0
           {"PM", _ } -> 12
           _ -> :error
         end
    tf_s = (hh + ap) |> rem(24) |> Integer.to_string
    tf_s = case String.length(tf_s) do
             1 -> "0"<>tf_s
             _ -> tf_s
           end
    IO.puts(tf_s<>":"<>mm_s<>":"<>ss_s)
  end
end

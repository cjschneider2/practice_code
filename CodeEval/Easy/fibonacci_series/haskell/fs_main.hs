import System.Environment (getArgs)

main = do
	[inpFile] <- getArgs
	input <- readFile inpFile
	-- print your output to stdout
	mapM_ putStrLn $ lines input

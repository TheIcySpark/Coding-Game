main = do
    input_line <- getLine
    let n = read input_line :: Integer
    input_line <- getLine
    let p = read input_line :: Integer
    putStrLn(show $last [x| x<-[1..n-p], p^x <= n])


main :: IO()
main = do
    input_line <- getLine
    let input = words input_line
    let n = read (input!!0) :: Int
    let r = read (input!!1) :: Int
    print([x*r| x<- [0..n-1]])
    return ()
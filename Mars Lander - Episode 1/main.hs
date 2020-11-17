import System.IO
import Control.Monad

calculoVelocidad :: Int -> Int
calculoVelocidad v_speed
    | v_speed <= -32 = 4
    | otherwise = 0


main :: IO ()
main = do
    hSetBuffering stdout NoBuffering -- DO NOT REMOVE
    
    input_line <- getLine
    let surfacen = read input_line :: Int -- the number of points used to draw the surface of Mars.
    
    replicateM surfacen $ do
        input_line <- getLine
        return ()

    -- game loop
    forever $ do
        input_line <- getLine
        let input = words input_line
        let y = read (input!!1) :: Int
        let v_speed = read (input!!3) :: Int -- the vertical speed (in m/s), can be negative.
        let power = read (input!!6) :: Int -- the thrust power (0 to 4).
        
        putStrLn ("0 " ++ show(calculoVelocidad(v_speed)))
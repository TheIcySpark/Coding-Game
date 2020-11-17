import System.IO ()
import Control.Monad 
import Data.List

main :: IO()
main = do
    linea_entrada <- getLine
    let n = read linea_entrada :: Int

    lineas <- replicateM n getLine        

    let pis= map (\x -> read x :: Int) lineas
    let pis_ordenados = sort pis
    let duplas = zip pis_ordenados $ tail pis_ordenados
    let diferencia = map (\(x, y) -> abs $ x - y) duplas
    let menor = minimum diferencia
    print(menor)

    return()
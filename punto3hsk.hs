promedio :: [Float] -> Float
promedio = (\xs -> (foldr (+) 0 xs) / fromIntegral (length xs))

main :: IO ()
main = do
    let notas = [5.0, 4.8, 2.9, 5.0]
    putStrLn ("Notas: " ++ show notas)
    putStrLn ("Promedio: " ++ show (promedio notas))

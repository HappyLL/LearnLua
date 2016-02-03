function func(args)
    for k,v in pairs(args) do
        print(k,v)
    end
end

func({1,2,3})
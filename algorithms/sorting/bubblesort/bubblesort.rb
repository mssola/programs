

def bubblesort(list)
  return list if list.size <= 1

  els = 1
  loop do
    swapped = false
    1.upto(list.size - els) do |i|
      if list[i - 1] > list[i]
        list[i], list[i - 1] = list[i - 1], list[i]
        swapped = true
      end
    end
    break unless swapped
    els += 1
  end

  list
end


list = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]
list.each { |x| print "#{x} " }
puts

list = bubblesort(list)

list.each { |x| print "#{x} " }
puts

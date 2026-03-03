
program matrix_multiplication
    implicit none
    integer :: n, trials, t
    real(8) :: start, finish, total_time
    integer :: block_size
    n = 1500
    trials = 30
    block_size = 16

    call benchmark_all(n, trials, block_size)

end program

subroutine benchmark_all(n, trials, block_size)
    implicit none
    integer, intent(in) :: n, trials, block_size
    real(8), allocatable :: A(:,:), B(:,:), C(:,:)
    real(8) :: start, finish, total, time
    integer :: t

    allocate(A(n,n), B(n,n), C(n,n))

    call random_number(A)
    call random_number(B)

    print *, "Running ijk..."
    total = 0.0
    do t = 1, trials
        C = 0.0
        call cpu_time(start)
        call mmm_kji(A,B,C,n)
        call cpu_time(finish)
        time = finish - start
        total = total + (finish - start)
        print *, time
    end do
    print *, "Average time ijk:", total/trials

    deallocate(A,B,C)

end subroutine

subroutine mmm_ijk(A,B,C,n)
    implicit none
    integer, intent(in) :: n
    real(8), intent(in) :: A(n,n), B(n,n)
    real(8), intent(inout) :: C(n,n)
    integer :: i,j,k

    do i=1,n
        do j=1,n
            do k=1,n
                C(i,j) = C(i,j) + A(i,k)*B(k,j)
            end do
        end do
    end do
end subroutine

subroutine mmm_ikj(A,B,C,n)
    implicit none
    integer, intent(in) :: n
    real(8), intent(in) :: A(n,n), B(n,n)
    real(8), intent(inout) :: C(n,n)
    integer :: i,j,k

    do i=1,n
        do k=1,n
            do j=1,n
                C(i,j) = C(i,j) + A(i,k)*B(k,j)
            end do
        end do
    end do
end subroutine

subroutine mmm_jik(A,B,C,n)
    implicit none
    integer, intent(in) :: n
    real(8), intent(in) :: A(n,n), B(n,n)
    real(8), intent(inout) :: C(n,n)
    integer :: i,j,k

    do j=1,n
        do i=1,n
            do k=1,n
                C(i,j) = C(i,j) + A(i,k)*B(k,j)
            end do
        end do
    end do
end subroutine

subroutine mmm_jki(A,B,C,n)
    implicit none
    integer, intent(in) :: n
    real(8), intent(in) :: A(n,n), B(n,n)
    real(8), intent(inout) :: C(n,n)
    integer :: i,j,k

    do j=1,n
        do k=1,n
            do i=1,n
                C(i,j) = C(i,j) + A(i,k)*B(k,j)
            end do
        end do
    end do
end subroutine

subroutine mmm_kij(A,B,C,n)
    implicit none
    integer, intent(in) :: n
    real(8), intent(in) :: A(n,n), B(n,n)
    real(8), intent(inout) :: C(n,n)
    integer :: i,j,k

    do k=1,n
        do i=1,n
            do j=1,n
                C(i,j) = C(i,j) + A(i,k)*B(k,j)
            end do
        end do
    end do
end subroutine

subroutine mmm_kji(A,B,C,n)
    implicit none
    integer, intent(in) :: n
    real(8), intent(in) :: A(n,n), B(n,n)
    real(8), intent(inout) :: C(n,n)
    integer :: i,j,k

    do k=1,n
        do j=1,n
            do i=1,n
                C(i,j) = C(i,j) + A(i,k)*B(k,j)
            end do
        end do
    end do
end subroutine

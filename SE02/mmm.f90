
program matrix_multiplication
    implicit none
    integer :: n, trials, t
    real(8) :: start, finish, total_time
    integer :: block_size
    n = 200
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

    print *, "ORDERING IJK"
    total = 0.0
    do t = 1, trials
        C = 0.0
        call cpu_time(start)
        call mmm_ijk(A,B,C,n)
        call cpu_time(finish)
        time = finish - start
        total = total + (finish - start)
        print *, time
    end do
    print *, "Average time:", total/trials

    print *, "ORDERING IKJ"
    total = 0.0
    do t = 1, trials
        C = 0.0
        call cpu_time(start)
        call mmm_ikj(A,B,C,n)
        call cpu_time(finish)
        time = finish - start
        total = total + (finish - start)
        print *, time
    end do
    print *, "Average time:", total/trials

    print *, "ORDERING JIK"
    total = 0.0
    do t = 1, trials
        C = 0.0
        call cpu_time(start)
        call mmm_jik(A,B,C,n)
        call cpu_time(finish)
        time = finish - start
        total = total + (finish - start)
        print *, time
    end do
    print *, "Average time:", total/trials

    print *, "ORDERING JKI"
    total = 0.0
    do t = 1, trials
        C = 0.0
        call cpu_time(start)
        call mmm_jki(A,B,C,n)
        call cpu_time(finish)
        time = finish - start
        total = total + (finish - start)
        print *, time
    end do
    print *, "Average time:", total/trials

    print *, "ORDERING KIJ"
    total = 0.0
    do t = 1, trials
        C = 0.0
        call cpu_time(start)
        call mmm_kij(A,B,C,n)
        call cpu_time(finish)
        time = finish - start
        total = total + (finish - start)
        print *, time
    end do
    print *, "Average time ijk:", total/trials

    print *, "ORDERING KJI"
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

subroutine mmm_block(A,B,C,n,bs)
    implicit none
    integer, intent(in) :: n, bs
    real(8), intent(in) :: A(n,n), B(n,n)
    real(8), intent(inout) :: C(n,n)
    integer :: i,j,k,ii,jj,kk

    do ii = 1, n, bs
        do jj = 1, n, bs
            do kk = 1, n, bs

                do i = ii, min(ii+bs-1,n)
                    do j = jj, min(jj+bs-1,n)
                        do k = kk, min(kk+bs-1,n)
                            C(i,j) = C(i,j) + A(i,k)*B(k,j)
                        end do
                    end do
                end do

            end do
        end do
    end do

end subroutine
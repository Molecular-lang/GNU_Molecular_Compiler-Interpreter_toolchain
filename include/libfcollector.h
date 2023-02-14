
!
! Developer Sampling Collector interface include file

        interface

        ! Routine to record a sample in the experiment.
        subroutine collector_sample(name)
        character(len=*), intent(in) :: name
        end subroutine

        ! Routine to suspend data collection during an experiment.
        subroutine collector_pause()
        end subroutine

        ! Routine to resume data collection during an experiment.
        subroutine collector_resume()
        end subroutine

        ! Routine to stop all data collection and close the experiment.
        subroutine collector_terminate_expt()
        end subroutine

        end interface

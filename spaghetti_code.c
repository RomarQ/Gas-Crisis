#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/**
 * $_ consumption    _$ liters of gas per 100 kilometers
 * $_ tank_capacity  _$ Tank capacity in liters
 * $_ total_stations _$ Number of gas stations
 */
typedef struct x {
    float   consumption;
    int     tank_capacity;
    int     total_stations;
    struct station * head;
    struct station * tail;
} Start;

/**
 * $_ distance  _$ Distance from current station to the next
 * $_ gas_price _$ Price of the gas per liter on current station
 */
typedef struct station {
    int     id;
    int     distance;
    float   gas_price;
    struct station * next;
    struct station * prev;
} Station;

Start * start;
float max_distance = 0;
float gas_on_tank = 0;


int possible( Station * station ) {

    if ( start->tail == station )
        return 1;

    return ( max_distance >= station->distance ) ? possible( station->next ) : 0; 
}

Station * cheapestStation( Station * current , Station * limit_station , int * target_distance ) {

    if ( limit_station == start->tail )
        return limit_station;
    
    Station * cheapest = limit_station;

    while ( current != limit_station ) {

        if ( cheapest->gas_price > limit_station->gas_price )
            cheapest = limit_station;

        limit_station = limit_station->prev;

        if ( current != limit_station)
            *target_distance -= limit_station->distance;
    }

    return cheapest;
}

/**
 * Gets the next station where gas is cheaper, within the max_distance range
 * @[next_station] pointer updates to the respective next station
 * @return 1 if there is a cheaper station within the max_distance range
 * @return 0 else
 * 
 */
int getNextStation( Station * current , Station ** next_station , int * target_distance ) {

    float old_price = current->gas_price;

    *next_station = current->next;
    while ( *next_station != start->tail ) {

        if ( old_price >= (*next_station)->gas_price )
            return 1;

        *target_distance += (*next_station)->distance;

            if( *target_distance > max_distance ) {
                *target_distance -= (*next_station)->distance;
                break;
            }
        
        *next_station = (*next_station)->next;
    }

    // Returns the cheapest station from current to the last station within max_distance range
    *next_station = cheapestStation( current, *next_station, target_distance );
        
        if ( *next_station == start->tail )
            return 1;

    return 0;
}

void showPath( Station * current ) {

    int target_distance = 0;
    Station * next_station;
    float gas_needed, gas_needed_to_fill = gas_needed = 0;

    while ( current != start->tail ) {
        target_distance = current->distance;

        if ( getNextStation( current , &next_station , &target_distance ) ){
            gas_needed = (( target_distance * start->consumption) / 100) - gas_on_tank ;
            printf("%d %.2f\n", current->id, gas_needed);
            gas_on_tank = 0;
        }
        else {
            gas_needed = (( target_distance * start->consumption) / 100);
            gas_needed_to_fill = start->tank_capacity - gas_on_tank;
            gas_on_tank = start->tank_capacity ;
            printf("%d %.2f\n", current->id, gas_needed_to_fill);
            gas_on_tank -= gas_needed;
        }

        current = next_station;
    }

}

void freeAllStations( Station * current ) {

    if ( current == NULL )
        return;

    freeAllStations( current->next );
    free(current);
}

int main () {

    start   = ( Start * ) malloc ( sizeof( Start ) );
        if ( NULL == start )
            return -1;
    start->head     = ( Station * ) malloc ( sizeof( Station ) );
        if ( NULL == start->head )
            return -1;
    
    if ( scanf("%f", &start->consumption) ){};
    if ( scanf("%d", &start->tank_capacity) ){};
    if ( scanf("%d", &start->total_stations) ){};

    Station * aux_node = start->head;
    aux_node->next = aux_node->prev = NULL;
    int i=0;
    for (;  i <= start->total_stations  ;  i++ ) {

        if ( i == start->total_stations) {
            aux_node->next = NULL;
            aux_node->gas_price = INT_MAX;
            start->tail = aux_node;
            break;
        }

        aux_node->id = i;
        if ( scanf("%d %f", &aux_node->distance, &aux_node->gas_price) ){};

        aux_node->next = ( Station * ) malloc ( sizeof( Station ) );
        aux_node->next->prev = aux_node;
        aux_node = aux_node->next;
    }

    max_distance = ( start->tank_capacity * 100 ) / start->consumption;
        if (!possible( start->head ))
            printf("NO\n");
        else
            showPath( start->head );

    freeAllStations( start->head );
    free( start );
    return 0;
}
